/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:24:18 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/07/27 20:24:18 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

#include "get_next_line.h"

int		rd2l(int fd, t_gnl_list **line_list, t_line *last_line,
			t_gnl_list **fst_list);
int		set_txt2line(char **buff, long *sz_can_read, t_line *line, char *dup);
void	fill_all_text(t_line *line, char *dup, char *bff, size_t bff_cpy_len);
char	*mandatory_gnl(int fd, t_gnl_list **line_list, t_gnl_list **fst_list);

char	*get_next_line(int fd)
{
	static t_gnl_list	*fst_list = NULLP;
	t_gnl_list			*current_list;
	char				*resulting_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULLP);
	if (fst_list == NULLP && !init_list_at_end(&fst_list, fd))
		return (NULLP);
	current_list = fst_list;
	while (current_list->fd != fd && current_list->next)
		current_list = current_list->next;
	if (current_list->fd != fd && !init_list_at_end(&fst_list, fd))
		return (NULLP);
	current_list = fst_list;
	while (current_list->fd != fd && current_list->next)
		current_list = current_list->next;
	resulting_line = mandatory_gnl(fd, &current_list, &fst_list);
	return (resulting_line);
}

char	*mandatory_gnl(int fd, t_gnl_list	**line_list,
	t_gnl_list **fst_list)
{
	char			*line_text;

	line_text = NULLP;
	if (!(*line_list) || (*line_list)->fd != fd)
		return (NULLP);
	while (!(((*line_list)->fst_line)
			&& ((*line_list)->fst_line->is_ready_to_print))
		&& !(*line_list)->is_file_finished)
	{
		if (rd2l(fd, line_list, (*line_list)->fst_line, fst_list) == -1)
			return (NULLP);
	}
	if ((*line_list)->fst_line && (*line_list)->fst_line->text)
		line_text = get_line_text_and_pass_to_next((*line_list));
	if ((*line_list)->is_file_finished && !((*line_list)->fst_line))
		clean_list(fst_list, fd);
	return (line_text);
}

int	rd2l(int fd, t_gnl_list **line_list, t_line *last_line,
	t_gnl_list **fst_list)
{
	if ((*line_list)->buffer == NULLP)
	{
		(*line_list)->buffer = (char *)malloc(BUFFER_SIZE);
		if ((*line_list)->buffer == NULLP)
			return (-1);
		(*line_list)->bytes_read_in_buffer
			=read(fd, (*line_list)->buffer, BUFFER_SIZE);
		if ((*line_list)->bytes_read_in_buffer < 0)
			return (save_return(line_list, -1, fst_list, fd));
		(*line_list)->is_file_finished
			= ((*line_list)->bytes_read_in_buffer < BUFFER_SIZE
				|| (*line_list)->bytes_read_in_buffer == 0);
	}
	while ((*line_list)->bytes_read_in_buffer > 0)
	{
		if (last_line == NULLP)
			last_line = new_line((*line_list));
		if (last_line == NULLP)
			return (-1);
		if (set_txt2line(&((*line_list)->buffer),
				&((*line_list)->bytes_read_in_buffer), last_line, NULLP) == 0)
			return (-1);
		last_line = last_line->next;
	}
	return (save_return(line_list, 1, fst_list, fd));
}

//This function manages the text that a newly created line has.
//Dup could be set to anyhing as input, it is just as input to save a line.
int	set_txt2line(char **buff, long *sz_can_read, t_line *line, char *dup)
{
	char	*remaining_buff;
	long	cpy_len;
	long	i;

	cpy_len = 0;
	while (*(sz_can_read) != cpy_len
		&& (*buff)[cpy_len] != '\n' && (*buff)[cpy_len] != '\0')
		cpy_len++;
	if (*(sz_can_read) != cpy_len)
		cpy_len++;
	dup = (char *)malloc(line->text_len + cpy_len + 1);
	remaining_buff = (char *)malloc(*(sz_can_read) - cpy_len);
	if (dup == NULLP || remaining_buff == NULLP)
		return (0);
	fill_all_text(line, dup, (*buff), cpy_len);
	i = cpy_len;
	while (i < *(sz_can_read))
	{
		remaining_buff[i - cpy_len] = (*buff)[i];
		i++;
	}
	*(sz_can_read) = *(sz_can_read) - cpy_len;
	free((*buff));
	*buff = remaining_buff;
	return (1);
}

//This functions fills the new text for a line by combining its previous text
//if it had any and then its corresponding text from the buffer.
void	fill_all_text(t_line *line, char *dup, char *bff, size_t bff_cpy_len)
{
	size_t	i;

	i = 0;
	while (i < line->text_len)
	{
		dup[i] = line->text[i];
		i++;
	}
	i = 0;
	while (i < bff_cpy_len)
	{
		dup[line->text_len + i] = bff[i];
		i++;
	}
	dup[line->text_len + i] = '\0';
	if (line->text_len != 0)
		free(line->text);
	line->text = dup;
	line->text_len = line->text_len + bff_cpy_len;
	if (bff[bff_cpy_len - 1] == '\n' || bff[bff_cpy_len - 1] == '\0' )
		line->is_ready_to_print = YES;
	return ;
}

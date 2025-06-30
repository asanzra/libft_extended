/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:24:35 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/07/27 20:24:35 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//OPT 2: clean_list
//Cleans list and contents
//Used in: get_next_line
void	clean_list(t_gnl_list **fst_list, int fd)
{
	t_gnl_list	*cleaned_list;
	t_gnl_list	*parent_list;

	cleaned_list = (*fst_list);
	parent_list = NULLP;
	while (cleaned_list->fd != fd)
	{
		parent_list = cleaned_list;
		cleaned_list = cleaned_list->next;
	}
	if (cleaned_list == (*fst_list))
		(*fst_list) = cleaned_list->next;
	else
		parent_list->next = cleaned_list->next;
	if (cleaned_list->buffer)
		free(cleaned_list->buffer);
	free(cleaned_list);
}

//A return for when buffer is allocated but reading to it fails
//		OR for when buffer is fully read correctly
//Used in: read_data_into_list
int	save_return(t_gnl_list **list, int returnval, t_gnl_list **fst_list,
	int fd)
{
	free((*list)->buffer);
	(*list)->buffer = NULLP;
	(*list)->bytes_read_in_buffer = 0;
	if (returnval == -1)
	{
		while ((*list)->fst_line)
		{
			if ((*list)->fst_line->text)
				free ((*list)->fst_line->text);
			free((*list)->fst_line);
			(*list)->fst_line = (*list)->fst_line->next;
		}
		clean_list(fst_list, fd);
	}
	return (returnval);
}

//This function retrieves and returns text from a ready-to-print line,
//freeing itself and its text and passing on to the next line.
//Used in: get_next_line
char	*get_line_text_and_pass_to_next(t_gnl_list	*line_list)
{
	char	*line_text;
	t_line	*first_line;

	first_line = line_list->fst_line;
	line_text = first_line->text;
	line_list->fst_line = first_line->next;
	free(first_line);
	return (line_text);
}

//This function creates a new line and adds it to the list.
//the text for the line must be set with "set_text_to_line".
//Used in: 
t_line	*new_line(t_gnl_list *line_list)
{
	t_line	*new_line_ret;
	t_line	*last_line_in_list;

	new_line_ret = malloc(sizeof(t_line));
	if (new_line_ret == NULLP)
		return (NULLP);
	new_line_ret->is_ready_to_print = NO;
	new_line_ret->next = NULLP;
	new_line_ret->text = NULLP;
	new_line_ret->text_len = 0;
	last_line_in_list = line_list->fst_line;
	if (last_line_in_list == NULLP)
		line_list->fst_line = new_line_ret;
	else
	{
		while (last_line_in_list->next != NULLP)
			last_line_in_list = last_line_in_list->next;
		last_line_in_list->next = new_line_ret;
	}
	return (new_line_ret);
}

//Creates a new line list at the end of the list's list.
//Changes the first node if needed. 
//"Returns" new node by changing it by reference.
//Used in: gnl
int	init_list_at_end(t_gnl_list **fst_list, int fd)
{
	t_gnl_list	*last_list;
	t_gnl_list	*new_list;

	new_list = malloc(sizeof(t_gnl_list));
	if (new_list == NULLP)
		return (NO);
	new_list->fd = fd;
	new_list->fst_line = NULLP;
	new_list->is_file_finished = NO;
	new_list->buffer = NULLP;
	new_list->bytes_read_in_buffer = 0;
	new_list->next = NULLP;
	if ((*fst_list) == NULLP)
	{
		(*fst_list) = new_list;
		return (YES);
	}
	last_list = *fst_list;
	while ((last_list)->next)
		last_list = last_list->next;
	last_list->next = new_list;
	return (YES);
}

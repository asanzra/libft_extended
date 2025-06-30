/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:24:28 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/07/27 20:24:28 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# define NULLP 0

# define YES 1
# define NO 0

typedef struct s_line
{
	char			*text;
	size_t			text_len;
	struct s_line	*next;
	char			is_ready_to_print;
}	t_line;

typedef struct s_gnl_list
{
	int					fd;
	char				is_file_finished;
	t_line				*fst_line;
	char				*buffer;
	long				bytes_read_in_buffer;
	struct s_gnl_list	*next;
}	t_gnl_list;

int		save_return(t_gnl_list **list, int returnval, t_gnl_list **fst_list,
			int fd);
char	*get_line_text_and_pass_to_next(t_gnl_list	*line_list);
t_line	*new_line(t_gnl_list *line_list);
int		init_list_at_end(t_gnl_list **list, int fd);
void	clean_list(t_gnl_list **fst_list, int fd);

#endif
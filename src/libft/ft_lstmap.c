/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:47:21 by asanz-ra          #+#    #+#             */
/*   Updated: 2025/06/30 15:48:32 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_extended.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	if (lst == 0 || f == 0 || del == 0)
		return ((t_list *) 0);
	new_lst = (t_list *) 0;
	while (lst != 0)
	{
		new_content = (*f)(lst->content);
		if (new_content != 0)
			new_node = ft_lstnew(new_content);
		if (new_content == 0 || new_node == 0)
		{
			if (new_content != 0)
				free(new_content);
			ft_lstclear(&new_lst, del);
			return ((t_list *) 0);
		}
		ft_lstadd_back(&new_lst, new_node);
		new_node = new_node->next;
		lst = lst->next;
	}
	return (new_lst);
}

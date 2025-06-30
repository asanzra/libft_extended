/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:46:40 by asanz-ra          #+#    #+#             */
/*   Updated: 2025/06/30 15:48:32 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_extended.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*node_ad;

	node_ad = malloc(sizeof(t_list));
	if (node_ad == 0)
		return (0);
	node_ad->content = content;
	node_ad->next = (t_list *) 0;
	return (node_ad);
}

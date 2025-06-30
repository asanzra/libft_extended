/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:39:41 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/01/08 17:19:59 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dsts;
	char	*srcs;

	if (dst == src)
		return (dst);
	dsts = (char *) dst;
	srcs = (char *) src;
	i = 0;
	while (i < n)
	{
		dsts[i] = srcs[i];
		i++;
	}
	return (dst);
}

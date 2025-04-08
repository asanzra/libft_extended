/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:48:13 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/01/11 17:39:07 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*ptr_wrt;
	size_t	i;

	ptr = malloc(count * size);
	if (ptr != 0)
	{
		ptr_wrt = (char *) ptr;
		i = 0;
		while (i < count * size)
			ptr_wrt[i++] = 0;
	}
	return (ptr);
}

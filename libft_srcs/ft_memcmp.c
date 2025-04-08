/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:57:35 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/01/10 02:53:56 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sc1;
	unsigned char	*sc2;

	sc1 = (unsigned char *) s1;
	sc2 = (unsigned char *) s2;
	i = 0;
	while (n > 0)
	{
		if (sc1[i] != sc2[i])
			break ;
		i++ ;
		n-- ;
	}
	if (n > 0)
		return ((int)(sc1[i] - sc2[i]));
	return ((int)(0));
}

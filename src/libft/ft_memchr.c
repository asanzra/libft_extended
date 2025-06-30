/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:57:35 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/01/10 02:40:06 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

//Both chars and unsigned chars are 1 byte.
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sc;
	unsigned char	cc;

	sc = (unsigned char *) s;
	cc = (unsigned char) c;
	i = 0;
	while (n > 0)
	{
		if (sc[i] == cc)
			break ;
		i++ ;
		n-- ;
	}
	if (n > 0)
		return ((void *) sc + i);
	return ((void *)(0));
}

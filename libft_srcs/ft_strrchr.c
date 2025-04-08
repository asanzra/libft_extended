/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:14:41 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/01/10 00:54:04 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*match;
	size_t	i;
	size_t	slen;
	char	*result;

	slen = ft_strlen(s);
	match = (char *)s;
	c = c % 128;
	if (c == '\0')
		return (match + slen);
	i = 0;
	result = 0;
	while (i < ft_strlen(s))
	{
		if (match[i] == c)
			result = match + i;
		i++ ;
	}
	return (result);
}

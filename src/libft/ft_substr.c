/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:56:23 by asanz-ra          #+#    #+#             */
/*   Updated: 2025/06/30 15:48:32 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib_extended.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (start >= ft_strlen(s))
	{
		res = (char *) malloc(1);
		if (res == 0)
			return ((char *) 0);
		res[0] = '\0';
		return (res);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	res = (char *) malloc(len + 1);
	if (res == 0)
		return ((char *)0);
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}

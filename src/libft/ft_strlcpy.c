/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:09:16 by asanz-ra          #+#    #+#             */
/*   Updated: 2025/06/30 15:48:32 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "lib_extended.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	cpylen;

	srcsize = ft_strlen(src);
	if (dst == 0 || dstsize == 0)
		return (srcsize);
	cpylen = dstsize - 1;
	if (srcsize < cpylen)
		cpylen = srcsize;
	ft_memcpy(dst, src, cpylen);
	dst[cpylen] = '\0';
	return (srcsize);
}

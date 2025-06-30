/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:59:08 by asanz-ra          #+#    #+#             */
/*   Updated: 2025/06/30 15:48:32 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "lib_extended.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	cpylen;
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	cpylen = dstsize - dstlen - 1;
	if (srclen < cpylen)
		cpylen = srclen;
	ft_memcpy(dst + dstlen, src, cpylen);
	dst[dstlen + cpylen] = '\0';
	return (dstlen + srclen);
}

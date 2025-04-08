/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:20:49 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/01/08 19:05:31 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

//1. src < dst: left to right copy or risk overwrite
//MEMORY: Allocated memory string
//src       [ocated me] 
//dst          [ted memor]
//RESULT: Allocaocated mey string
//NOK RES:Allocaocaocaocao string ?
//
//2. src > dst: right to left memcpy
//MEMORY: Allocated memory string
//src		   [ted memor]
//dst		[ocated me]
//RESULT: Allted memorory string
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;

	if (src == dst)
		return (dst);
	d = (char *) dst;
	s = (char *) src;
	if (s > d)
		return (ft_memcpy(dst, src, len));
	while (len--)
		d[len] = s[len];
	return (dst);
}

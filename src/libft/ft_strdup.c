/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:51:43 by asanz-ra          #+#    #+#             */
/*   Updated: 2025/06/30 15:48:32 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "lib_extended.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	buf_size;
	char	*dup;

	buf_size = ft_strlen(s1) + 1;
	dup = (char *) malloc(buf_size);
	if (dup == 0)
		return ((char *) 0);
	ft_strlcpy(dup, s1, buf_size);
	return (dup);
}

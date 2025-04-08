/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:58:07 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/01/11 17:41:42 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	char	*res;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	res = (char *) malloc(size1 + size2 + 1);
	if (res == 0)
		return ((char *)(0));
	ft_strlcpy(res, s1, size1 + 1);
	ft_strlcpy(res + size1, s2, size2 + 1);
	return (res);
}

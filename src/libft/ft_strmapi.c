/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:26:07 by asanz-ra          #+#    #+#             */
/*   Updated: 2025/06/30 15:48:32 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib_extended.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			strlen;
	char			*str;
	unsigned int	i;

	strlen = ft_strlen(s);
	str = (char *) malloc(strlen + 1);
	if (str == 0)
		return ((char *) 0);
	i = 0;
	while (i < strlen)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[strlen] = '\0';
	return (str);
}

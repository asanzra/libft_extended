/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:49:36 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/02/11 13:57:36 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	strlen;
	size_t	i;

	strlen = ft_strlen(s);
	i = 0;
	while (i < strlen)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

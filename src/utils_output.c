/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:35:23 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/12/12 21:30:41 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Prints 1 char to stdout.
//Returns no. of bytes printed (1 if OK)
int	print_char(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

//Prints str to stdout. 
//Returns -1 if error encountered and no. of bytes printed if OK 
int	print_str(const char *str)
{
	int		i;
	int		status;

	i = 0;
	while (str[i])
	{
		status = print_char(str[i]);
		if (status != 1)
			return (-1);
		i++;
	}
	return (i);
}

void	ft_strlcat_no_minus(char *new_str, char *str, size_t dstsize)
{
	if (str[0] != '-')
		ft_strlcat(new_str, str, dstsize);
	else
		ft_strlcat(new_str, str + 1, dstsize);
}

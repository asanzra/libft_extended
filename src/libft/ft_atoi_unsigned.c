/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 03:54:12 by asanz-ra          #+#    #+#             */
/*   Updated: 2025/09/27 22:06:27 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "lib_extended.h"

void	skip_spaces(char *c, size_t *i, const char *str);

//This functions transforms a string into an unsigned int, checking that the 
//string was NOT representing a number larger than the max unsigned int. If too
// big, 0 is returned.
//
//It skips all kinds of spaces (isspace3) and plus ('+') signs after that
//If no digits are present after spaces and signs, a 0 is also returned
//
//One may use the is_atoi_error() function to check if the 0 return is real or
//just the sign of an error. It returns 1 if it was an error, or 0 if it wasn't
// Example: if(is_atoi_error(str)) -> real failure, 0 is a fake result
unsigned int	ft_atoi_unsigned(const char *str)
{
	size_t			i;
	char			c;
	unsigned long	unsig_result;

	i = 0;
	c = str[i];
	skip_spaces(&c, &i, str);
	if (!ft_isdigit(c))
		return (0);
	unsig_result = 0;
	while (ft_isdigit(c))
	{
		unsig_result *= 10;
		unsig_result += c - '0';
		if (unsig_result > 4294967295)
			return (0);
		c = str[++i];
	}
	return ((unsigned int)unsig_result);
}

void	skip_spaces(char *c, size_t *i, const char *str)
{
	while ((*c) == ' ' || (*c) == '\f' || (*c) == '\n' || (*c) == '\r'
		|| (*c) == '\t' || (*c) == '\v')
		(*c) = str[++(*i)];
	while ((*c) == '+')
		(*c) = str[++(*i)];
	return ;
}

//This function returns 1 is ft_atoi_unsigned has an error (either parsing
// or an overflow) and 0 if it didn't.
//It is useful to check when the returned 0 from the main function means 
// there was an error.
// Example: if(is_atoi_error(str)) -> real failure, 0 is a fake result
char	ft_atoi_unsigned_is_error(const char *str)
{
	size_t			i;
	char			c;
	unsigned long	unsig_result;

	i = 0;
	c = str[i];
	skip_spaces(&c, &i, str);
	if (!ft_isdigit(c))
		return (1);
	unsig_result = 0;
	while (ft_isdigit(c))
	{
		unsig_result *= 10;
		unsig_result += c - '0';
		if (unsig_result > 4294967295)
			return (1);
		c = str[++i];
	}
	return (0);
}

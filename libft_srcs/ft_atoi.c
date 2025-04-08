/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 03:54:12 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/01/11 17:37:41 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	get_sign_skip_spaces(char *c, size_t *i, const char *str);
char	is_overflowed(unsigned long unsig_result, char sign);

//This functions transforms a string into an int, checking that the string 
//was NOT representing a number larger than an int. If too big, -1 is returned
//
//It skips all kinds of spaces (isspace3) and repetared signs after a first '-'
//If no digits are present after spaces and signs, a -1 is returned
//
//One may use the is_atoi_error() function to check if the -1 return is real
//just the sign of an error.
// Example: if(is_atoi_error(str)) -> real failure, -1 is a fake result
int	ft_atoi(const char *str)
{
	size_t			i;
	char			c;
	char			sign;
	unsigned long	unsig_result;

	i = 0;
	c = str[i];
	sign = get_sign_skip_spaces(&c, &i, str);
	if (!ft_isdigit(c))
		return (-1);
	unsig_result = 0;
	while (ft_isdigit(c))
	{
		unsig_result *= 10;
		unsig_result += c - '0';
		if (is_overflowed(unsig_result, sign))
			return (-1);
		c = str[++i];
	}
	return (sign * (unsigned int)unsig_result);
}

char	get_sign_skip_spaces(char *c, size_t *i, const char *str)
{
	char	sign;

	sign = 1;
	while ((*c) == ' ' || (*c) == '\f' || (*c) == '\n' || (*c) == '\r'
		|| (*c) == '\t' || (*c) == '\v')
		(*c) = str[++(*i)];
	while ((*c) == '+' || (*c) == '-')
	{
		if ((*c) == '-')
			sign = -1;
		(*c) = str[++(*i)];
	}
	return (sign);
}

//Checks if the passed unsigned long is bigger than an int
char	is_overflowed(unsigned long unsig_result, char sign)
{
	char	overflow;

	overflow = 0;
	if (sign == 1 && (unsig_result > __INT_MAX__))
		overflow = 1;
	if (sign == -1 && ((unsig_result - 1) > __INT_MAX__))
		overflow = 1;
	return (overflow);
}

//This function returns 1 is atoi has an error (either parsing or an overflow)
// and 0 if it didn't.
//It is useful to check when the returned -1 from the main function means 
// there was an error.
// Example: if(is_atoi_error(str)) -> real failure, -1 is a fake result
char	ft_atoi_is_error(const char *str)
{
	size_t			i;
	char			c;
	char			sign;
	unsigned long	unsig_result;

	i = 0;
	c = str[i];
	sign = get_sign_skip_spaces(&c, &i, str);
	if (!ft_isdigit(c))
		return (1);
	unsig_result = 0;
	while (ft_isdigit(c))
	{
		unsig_result *= 10;
		unsig_result += c - '0';
		if (is_overflowed(unsig_result, sign))
			return (1);
		c = str[++i];
	}
	return (0);
}

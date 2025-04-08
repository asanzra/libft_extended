/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:47:06 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/02/12 12:33:47 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static int	get_digit_count(long n);
static void	fill_str(char *str, long n, size_t strlen, int negative);

//Allocates and returns a string made from a signed integer (with - if neg.)
char	*ft_itoa(int n)
{
	size_t	strlen;
	char	*str;
	long	num;
	int		negative;

	num = (long) n;
	strlen = 0;
	negative = 0;
	if (num < 0)
	{
		num = -num;
		strlen++;
		negative = 1;
	}
	strlen += get_digit_count(num);
	str = (char *) malloc(strlen + 1);
	if (str == 0)
		return ((char *) 0);
	fill_str(str, num, strlen, negative);
	return (str);
}

//Gets the number of digits in an intger by removing every last digit until 
//the integer is reduced to 0 (until no more digits left).
//Example: 9045->904->90->9->0 (4 changes=4 digits)
//For input of 0, the loop would return 0 digits, so we discard this case.
static int	get_digit_count(long num)
{
	int	count;

	if (num == 0)
		return (1);
	count = 0;
	while (num > 0)
	{
		num = num - num % 10;
		num = num / 10;
		count ++;
	}
	return (count);
}

//First fills symbol (-) then string from the last digit, then terminates it.
static void	fill_str(char *str, long num, size_t strlen, int negative)
{
	int	write_i;
	int	first_i;
	int	digit;

	first_i = 0;
	if (negative)
	{
		str[0] = '-';
		first_i = 1;
	}
	write_i = strlen - 1;
	while (write_i >= first_i)
	{
		digit = num % 10;
		num = num - digit;
		num = num / 10;
		str[write_i] = '0' + digit;
		write_i --;
	}
	str[strlen] = '\0';
}

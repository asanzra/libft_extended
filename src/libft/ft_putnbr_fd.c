/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:07:39 by asanz-ra          #+#    #+#             */
/*   Updated: 2025/06/30 15:48:32 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_extended.h"

static int	get_digit_count(long num);
static void	fill_str(int fd, long num, int digit_count, int negative);
static long	power(int base, unsigned int exp);

void	ft_putnbr_fd(int n, int fd)
{
	int		digit_count;
	long	num;
	int		negative;

	num = (long) n;
	negative = 0;
	if (num < 0)
	{
		num = -num;
		negative = 1;
	}
	digit_count = get_digit_count(num);
	fill_str(fd, num, digit_count, negative);
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

//First fills symbol (-) then string from number.
//If (digit_count) is 4 (i.e. for 7463), 7 represents 7*10³ (digit_count-1)
static void	fill_str(int fd, long num, int digit_count, int negative)
{
	int		digit_i;
	long	digit_value;
	int		digit;

	if (negative == 1)
		ft_putchar_fd('-', fd);
	digit_i = 0;
	while (digit_i < digit_count)
	{
		digit_value = power(10, digit_count - digit_i - 1);
		digit = num / digit_value;
		num = num - digit * digit_value;
		ft_putchar_fd('0' + digit, fd);
		digit_i ++;
	}
}

static long	power(int base, unsigned int exp)
{
	long	res;

	res = 1;
	while (exp > 0)
	{
		res *= base;
		exp --;
	}
	return (res);
}

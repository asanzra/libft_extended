/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:24:37 by asanz-ra          #+#    #+#             */
/*   Updated: 2025/06/30 15:49:24 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "lib_extended.h"
#include "libft.h"

char	long_is_negative_and_go_positive(long *n)
{
	char	is_n;
	long	min;

	min = -9223372036854775807;
	min -= 1;
	is_n = 0;
	if (*n < 0)
	{
		is_n = 1;
		if ((*n) == min)
		{
			is_n = 2;
			(*n) += 1;
		}
		*n = -(*n);
	}
	return (is_n);
}

// Allocates a string with the conversion of a long,
// Converts to the base passed as second argument.
// Returns NULL if error allocating or wrong base.
// Base can't have '+','-',less than 2 char, or repeated chars
// Example bases: decimal "0123456789", hex "0123456789abcdef",
// HEX "0123456789ABCDEF", octal "01234567", binary "01",
// usr can define any custom one. for example: six-base "abc123"
char	*ft_itoa_base_long(long n, char *base)
{
	long unsigned int	base_size;
	unsigned long long	digits[70];
	int					digit_pos;
	char				is_neg;

	base_size = ft_strlen(base);
	if (wrong_base(base, base_size))
		return (NULL);
	is_neg = long_is_negative_and_go_positive(&n);
	digit_pos = 0;
	while ((n > 0 || digit_pos == 0) && digit_pos < (70 - 1))
	{
		digits[digit_pos] = n % base_size;
		if (is_neg == 2 && digits[digit_pos] != base_size - 1)
		{
			digits[digit_pos]++;
			is_neg = 1;
		}
		else if (is_neg == 2 && digits[digit_pos] == base_size - 1)
			digits[digit_pos] = 0;
		n = (n - digits[digit_pos]) / base_size;
		digit_pos++;
	}
	return (alloc_str_rev_end_lim(digits, base, digit_pos));
}

// Allocates a string with the conversion of an unsigned long,
// Converts to the base passed as second argument.
// Returns NULL if error allocating or wrong base.
// Base can't have '+','-',less than 2 char, or repeated chars
// Example bases: decimal "0123456789", hex "0123456789abcdef",
// HEX "0123456789ABCDEF", octal "01234567", binary "01",
// usr can define any custom one. for example: six-base "abc123"
char	*ft_itoa_unsigned_base_long(unsigned long long n, char *base)
{
	unsigned long long		base_size;
	unsigned long long		digits[70];
	int						digit_pos;

	base_size = ft_strlen(base);
	if (wrong_base(base, base_size))
		return (NULL);
	digit_pos = 0;
	while (n != 0 && digit_pos < (70 - 1))
	{
		digits[digit_pos] = n % base_size;
		n = (n - digits[digit_pos]) / base_size;
		digit_pos++;
	}
	return (alloc_str_rev_end_lim(digits, base, digit_pos));
}

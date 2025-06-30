/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:24:37 by asanz-ra          #+#    #+#             */
/*   Updated: 2025/06/30 15:48:32 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "lib_extended.h"

char	*alloc_str_rev_end_lim(unsigned long long *digits, char *base, int lim)
{
	int		digit_pos;
	char	*str;

	if (lim == 0)
		str = (char *)malloc(2);
	else
		str = (char *)malloc(lim + 1);
	if (str == NULL)
		return (NULL);
	if (lim == 0)
	{
		str[0] = base[0];
		str[1] = '\0';
		return (str);
	}
	digit_pos = 0;
	while (digit_pos < lim)
	{
		str[lim - 1 - digit_pos] = base[digits[digit_pos]];
		digit_pos++;
	}
	str[lim] = '\0';
	return (str);
}

void	check_negative(long *n)
{
	if (*n < 0)
	{
		write(1, "-", 1);
		*n = -(*n);
	}
}

int	wrong_base(char *base, int base_size)
{
	int	i;
	int	j;

	if (base_size < 2)
		return (1);
	i = 0;
	while (i < base_size)
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = 0;
		while (j < base_size)
		{
			if (j != i && base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// Allocates a string with the conversion of an int,
// Converts to the base passed as second argument.
// Returns NULL if error allocating or wrong base.
// Base can't have '+','-',less than 2 char, or repeated chars
// Example bases: decimal "0123456789", hex "0123456789abcdef",
// HEX "0123456789ABCDEF", octal "01234567", binary "01",
// usr can define any custom one. for example: six-base "abc123"
char	*ft_itoa_base(int nbr, char *base)
{
	int					base_size;
	unsigned long long	digits[40];
	int					digit_pos;
	long				n;

	n = 0 + nbr;
	base_size = ft_strlen(base);
	if (wrong_base(base, base_size))
		return (NULL);
	check_negative(&n);
	if (n < 0)
		return (NULL);
	digit_pos = 0;
	while ((n > 0 || digit_pos == 0) && digit_pos < (40 - 1))
	{
		digits[digit_pos] = n % base_size;
		n = (n - digits[digit_pos]) / base_size;
		digit_pos++;
	}
	return (alloc_str_rev_end_lim(digits, base, digit_pos));
}

// Allocates a string with the conversion of an unsigned int,
// Converts to the base passed as second argument.
// Returns NULL if error allocating or wrong base.
// Base can't have '+','-',less than 2 char, or repeated chars
// Example bases: decimal "0123456789", hex "0123456789abcdef",
// HEX "0123456789ABCDEF", octal "01234567", binary "01",
// usr can define any custom one. for example: six-base "abc123"
char	*ft_itoa_unsigned_base(unsigned int nbr, char *base)
{
	int					base_size;
	unsigned long long	digits[40];
	int					digit_pos;
	long				n;

	n = 0 + nbr;
	base_size = ft_strlen(base);
	if (wrong_base(base, base_size))
		return (NULL);
	check_negative(&n);
	if (n < 0)
		return (NULL);
	digit_pos = 0;
	while ((n > 0 || digit_pos == 0) && digit_pos < (40 - 1))
	{
		digits[digit_pos] = n % base_size;
		n = (n - digits[digit_pos]) / base_size;
		digit_pos++;
	}
	return (alloc_str_rev_end_lim(digits, base, digit_pos));
}

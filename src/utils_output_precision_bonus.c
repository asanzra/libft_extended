/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_output_precision_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:51:41 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/12/15 00:35:19 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str_precision_str(char *str, size_t precision)
{
	char	*new_str;
	size_t	dstsize;
	int		result;

	dstsize = precision + 1;
	new_str = (char *) malloc(dstsize);
	if (new_str == NULL)
		return (-1);
	ft_strlcpy(new_str, str, dstsize);
	result = print_str(new_str);
	free(new_str);
	return (result);
}

void	fill_starting_zeros(char *new_str, size_t dstsize, int zeros,
	char flag_is_neg_hex)
{
	char	is_neg;

	is_neg = (flag_is_neg_hex > 0);
	if (zeros <= 0)
		return ;
	if (!is_neg)
	{
		if (flag_is_neg_hex > -1)
			ft_strlcpy(new_str, "0", dstsize);
	}
	else
	{
		ft_strlcpy(new_str, "-", dstsize);
		ft_strlcat(new_str, "0", dstsize);
	}
	zeros--;
	while (zeros > 0)
	{
		ft_strlcat(new_str, "0", dstsize);
		zeros--;
	}
}

int	print_str_precision_int(char *str, size_t precision, char *flags_len_m_conv)
{
	char	*new_str;
	size_t	dstsize;
	int		result;
	char	is_neg;
	char	flag_is_neg_hex;

	is_neg = (str[0] == '-');
	flag_is_neg_hex = -(flags_len_m_conv[9] == 'x' && flags_len_m_conv[0] == 1)
		- 2 * (flags_len_m_conv[9] == 'X' && flags_len_m_conv[0] == 1) + is_neg;
	if (remove_starting_hex_special(&str, flags_len_m_conv) == -1)
		return (-1);
	if ((ft_strlen(str) - (is_neg)) >= precision)
		return (print_str(str));
	dstsize = precision + 1 + (is_neg) + 2 * (flag_is_neg_hex <= -1);
	new_str = (char *) malloc(dstsize);
	if (new_str == NULL)
		return (-1);
	if (add_starting_hex_special(&new_str, flag_is_neg_hex, dstsize) == -1)
		return (-1);
	fill_starting_zeros(new_str, dstsize,
		precision - (ft_strlen(str) - (is_neg)), flag_is_neg_hex);
	ft_strlcat_no_minus(new_str, str, dstsize);
	result = print_str(new_str);
	free(new_str);
	return (result);
}

int	print_str_precision(char *str, int precision, char *flags_len_m_conv)
{
	size_t	new_prec;

	if (precision < 0)
		return (print_str(str));
	new_prec = (size_t)(precision);
	if (flags_len_m_conv[9] == 's')
		return (print_str_precision_str(str, new_prec));
	else if (flags_len_m_conv[9] == 'd' || flags_len_m_conv[9] == 'i'
		|| flags_len_m_conv[9] == 'o' || flags_len_m_conv[9] == 'u'
		|| flags_len_m_conv[9] == 'x' || flags_len_m_conv[9] == 'X')
		return (print_str_precision_int(str, new_prec, flags_len_m_conv));
	else
		return (print_str(str));
}

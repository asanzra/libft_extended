/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:35:36 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/12/15 00:36:44 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

////TODO: Use flags, length mod. and precision
// Used flag - and 0 and .
int	ft_printf_integer(char *flags_len_m_conv, int *fw_precision,
			int *printed_chars, va_list args)
{
	char	*int_str;
	int		bytes_printed;

	int_str = ft_itoa(va_arg(args, int));
	if (int_str[0] != '-' && flags_len_m_conv[4])
		add_positive_sign_for_d_i("+", &int_str);
	else if (int_str[0] != '-' && flags_len_m_conv[3])
		add_positive_sign_for_d_i(" ", &int_str);
	if (int_str == NULL)
		return (-1);
	bytes_printed = print_str_fw(int_str, fw_precision, flags_len_m_conv);
	free(int_str);
	if (bytes_printed == -1)
		return (-1);
	(*printed_chars) += bytes_printed;
	flags_len_m_conv++;
	fw_precision++;
	return (1);
}

////TODO: Use flags, length mod. and precision
// Used flag - and 0 and .
int	ft_printf_unisgned10(char *flags_len_m_conv, int *fw_precision,
			int *printed_chars, va_list args)
{
	char	*int_str;
	int		bytes_printed;

	int_str = ft_unsigned_itoa(va_arg(args, unsigned int));
	if (int_str == NULL)
		return (-1);
	bytes_printed = print_str_fw(int_str, fw_precision, flags_len_m_conv);
	free(int_str);
	if (bytes_printed == -1)
		return (-1);
	(*printed_chars) += bytes_printed;
	flags_len_m_conv++;
	fw_precision++;
	return (1);
}

int	add_hex_prefix(char *prefix, char **int_str)
{
	char	*temp;

	temp = (char *) malloc(ft_strlen((*int_str)) + 3);
	if (temp == 0)
		return (-1);
	ft_strlcpy(temp, prefix, ft_strlen((*int_str)) + 3);
	ft_strlcat(temp, (*int_str), ft_strlen((*int_str)) + 3);
	free((*int_str));
	(*int_str) = temp;
	return (1);
}

////TODO: Use flags, length mod. and precision
// Used flag - and 0 and .
int	ft_printf_base16(char *flags_len_m_conv, int *fw_precision,
			int *printed_chars, va_list args)
{
	char	*int_str;
	int		bytes_printed;
	char	is_not_zero;

	bytes_printed = 0;
	int_str = ft_itoa_unsigned_base(va_arg(args, unsigned int),
			"0123456789abcdef");
	if (int_str == NULL)
		return (-1);
	is_not_zero = int_str[0] != '0';
	if (flags_len_m_conv[0] == 1 && is_not_zero)
	{
		if (add_hex_prefix("0x", &int_str) < 1)
			return (-1);
	}
	bytes_printed += print_str_fw(int_str, fw_precision, flags_len_m_conv);
	free(int_str);
	if (bytes_printed < (2 * (flags_len_m_conv[0] == 1 && is_not_zero)))
		return (-1);
	(*printed_chars) += bytes_printed;
	fw_precision++;
	return (1);
}

////TODO: Use flags, length mod. and precision
// Used flag - and 0 and .
int	ft_printf_base16up(char *flags_len_m_conv, int *fw_precision,
			int *printed_chars, va_list args)
{
	char	*int_str;
	int		bytes_printed;
	char	is_not_zero;

	bytes_printed = 0;
	int_str = ft_itoa_unsigned_base(va_arg(args, unsigned int),
			"0123456789ABCDEF");
	if (int_str == NULL)
		return (-1);
	is_not_zero = int_str[0] != '0';
	if (flags_len_m_conv[0] == 1 && is_not_zero)
	{
		if (add_hex_prefix("0X", &int_str) < 1)
			return (-1);
	}
	bytes_printed += print_str_fw(int_str, fw_precision, flags_len_m_conv);
	free(int_str);
	if (bytes_printed < (2 * (flags_len_m_conv[0] == 1 && is_not_zero)))
		return (-1);
	(*printed_chars) += bytes_printed;
	fw_precision++;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_strings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:02:37 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/12/12 21:33:10 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

////TODO: Use flags, length mod. and precision
// Used flag - and 0 and .(dont apply)
int	ft_printf_percent(char *flags_len_m_conv, int *fw_precision,
			int *printed_chars, va_list args)
{
	if (print_char('%') != 1)
		return (-1);
	(*printed_chars)++;
	flags_len_m_conv++;
	fw_precision++;
	args++;
	return (1);
}

////TODO: Use flags, length mod. and precision
// Used flag - and 0
// Used flag . (dont apply)
int	ft_printf_char(char *flags_len_m_conv, int *fw_precision,
			int *printed_chars, va_list args)
{
	unsigned char	c;
	char			*str;

	c = (unsigned char) va_arg(args, int);
	str = (char *) malloc(2);
	if (str == 0)
		return (-1);
	str[0] = (char) c;
	str[1] = '\0';
	(*printed_chars) += print_char_fw(str, fw_precision, flags_len_m_conv);
	free(str);
	return (1);
}

////TODO: Use flags, length mod. and precision
// Used flag - and 0 and .
int	ft_printf_string(char *flags_len_m_conv, int *fw_precision,
			int *printed_chars, va_list args)
{
	char		*str;
	int			bytes_printed;

	str = (char *) va_arg(args, const char *);
	if (str == 0)
		str = "(null)";
	bytes_printed = print_str_fw(str, fw_precision, flags_len_m_conv);
	if (bytes_printed == -1)
		return (-1);
	(*printed_chars) += bytes_printed;
	flags_len_m_conv++;
	fw_precision++;
	return (1);
}

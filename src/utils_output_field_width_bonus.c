/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_output_field_width_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:27:12 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/12/14 23:41:03 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_padding(size_t padding, char padding_char, char *flags_len_m_conv,
			char *str);
void	set_padding_char_fw_sign_minus_flag(char *padding_char, int *fw,
			char *flags_len_m_conv);

//Prints str to stdout taking into account a minimum field width.
//Returns -1 if error encountered and no. of bytes printed with padding if OK 
//
// An optional decimal digit string (with nonzero first digit) specifying a 
// minimum field width.  If the converted value has fewer characters than the 
// field width, it will be padded with  spaces on  the left (or right, if the 
// left-adjustment flag has been given).  Instead of a decimal digit string one 
// may write "*" or "*m$" (for some decimal integer m) to specify that the field
// width is given in the next argument, or in the m-th argument, respectively, 
// which must be of type int.  A negative field width is taken as a '-' flag 
// followed by a positive field width.  In no case does a nonexistent or small 
// field width cause truncation of a field; if the result of a conversion is 
// wider than the field width, the field is expanded to contain 
//the conversion result.
int	print_str_fw(char *str, int *fw_prec, char *flags_len_m_conv)
{
	size_t	padding;
	int		temp;
	int		result;
	char	padding_char;
	int		fw;

	result = 0;
	fw = fw_prec[0];
	set_padding_char_fw_sign_minus_flag(&padding_char, &fw, flags_len_m_conv);
	if (ft_abs(fw) <= ft_strlen(str))
		return (print_str_precision(str, fw_prec[1], flags_len_m_conv));
	padding = ft_abs(fw) - ft_strlen(str);
	if (fw > 0)
		result += print_padding(padding, padding_char, flags_len_m_conv, str);
	temp = print_str_precision(str, fw_prec[1], flags_len_m_conv);
	if (temp == -1)
		return (result);
	result += temp;
	if (fw < 0)
		result += print_padding(padding, padding_char, flags_len_m_conv, str);
	return (result);
}

int	print_char_fw(char *str, int *fw_prec, char *flags_len_m_conv)
{
	size_t	padding;
	int		temp;
	int		result;
	char	padding_char;
	int		fw;

	result = 0;
	fw = fw_prec[0];
	set_padding_char_fw_sign_minus_flag(&padding_char, &fw, flags_len_m_conv);
	if (ft_abs(fw) <= 1)
		return (print_char(str[0]));
	padding = ft_abs(fw) - 1;
	if (fw > 0)
		result += print_padding(padding, padding_char, flags_len_m_conv, str);
	temp = print_char(str[0]);
	if (temp != 1)
		return (result);
	result += temp;
	if (fw < 0)
		result += print_padding(padding, padding_char, flags_len_m_conv, str);
	return (result);
}

void	set_padding_char_fw_sign_minus_flag(char *padding_char, int *fw,
			char *flags_len_m_conv)
{
	(*padding_char) = ' ';
	if (flags_len_m_conv[1] && !flags_len_m_conv[2] && (*fw) >= 0)
		(*padding_char) = '0';
	if (flags_len_m_conv[2] && (*fw) > 0)
		(*fw) = -(*fw);
	if ((*fw) < 0)
		flags_len_m_conv[2] = 1;
}

int	print_padding(size_t padding, char padding_char, char *flags_len_m_conv,
	char *str)
{
	size_t	printed_pad_chars;

	printed_pad_chars = 0;
	if ((flags_len_m_conv[9] == 'd' || flags_len_m_conv[9] == 'i')
		&& str[0] == '-'
		&& flags_len_m_conv[2] == 0 && flags_len_m_conv[1] == 1)
	{
		if (print_char('-') != 1)
			return (printed_pad_chars);
		printed_pad_chars++;
		str[0] = '0';
	}
	while (printed_pad_chars < padding)
	{
		if (print_char(padding_char) != 1)
			return (printed_pad_chars);
		printed_pad_chars++;
	}
	return ((int)printed_pad_chars);
}

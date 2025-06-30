/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:15:06 by asanz-ra          #+#    #+#             */
/*   Updated: 2025/06/30 17:02:47 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Upon successful return, these functions return the number 
//of characters printed 
//(excluding the null byte used to end output to strings).
int	ft_printf(const char *format, ...)
{
	size_t	main_iterator;
	int		printed_chars;
	int		format_parser_return_value;
	va_list	arguments;

	main_iterator = 0;
	printed_chars = 0;
	va_start(arguments, format);
	while ('\0' != format[main_iterator])
	{
		if (format[main_iterator] != '%')
			print_char_no_conversion(format, &main_iterator, &printed_chars);
		else
		{
			format_parser_return_value = format_parser(format,
					&main_iterator, &printed_chars, arguments);
			if (format_parser_return_value < 0)
				return (format_parser_return_value);
		}
	}
	va_end(arguments);
	return (printed_chars);
}

void	print_char_no_conversion(const char *format,
	size_t *main_iterator, int *printed_chars)
{
	print_char(format[(*main_iterator)]);
	(*printed_chars)++;
	(*main_iterator)++;
}

//This function parses a conversion specfication and prints its result,
//it also adds the number of printed characters to the total.
//The overall syntax of a conversion specification is:
//%[flags][width][.precision][length modifier]conversion
int	format_parser(const char *format, size_t *format_index,
	int *printed_chars, va_list arguments)
{
	char	flags_length_mod_conversion[FLAG_TOTAL_NO
		+ LENGTH_MOD_LENGTH + CONVERSION_LENGTH];
	int		field_width;
	int		precision;
	int		field_width_and_precision[2];

	if (format[*format_index] != '%')
		return (-1);
	(*format_index)++;
	flag_parser (format, format_index, flags_length_mod_conversion);
	field_width = field_width_parser(format, format_index);
	precision = precision_parser(format, format_index);
	if (length_mod_conversion_parser(
			flags_length_mod_conversion, format, format_index) < 0)
		return (-2);
	field_width_and_precision[0] = field_width;
	field_width_and_precision[1] = precision;
	if (conversion_map_redirect(flags_length_mod_conversion,
			field_width_and_precision, printed_chars, arguments) < 0)
		return (-3);
	return (1);
}

int	conversion_map_redirect(char *flags,
	int *fw_precision, int *printed_chars, va_list args)
{
	if (flags[FLAG_TOTAL_NO + LENGTH_MOD_LENGTH] == '%')
		return (ft_printf_percent(flags, fw_precision, printed_chars, args));
	if (flags[FLAG_TOTAL_NO + LENGTH_MOD_LENGTH] == 'c')
		return (ft_printf_char(flags, fw_precision, printed_chars, args));
	if (flags[FLAG_TOTAL_NO + LENGTH_MOD_LENGTH] == 's')
		return (ft_printf_string(flags, fw_precision, printed_chars, args));
	if (flags[FLAG_TOTAL_NO + LENGTH_MOD_LENGTH] == 'p')
		return (ft_printf_pointer(flags, fw_precision, printed_chars, args));
	if (flags[FLAG_TOTAL_NO + LENGTH_MOD_LENGTH] == 'd'
		|| flags[FLAG_TOTAL_NO + LENGTH_MOD_LENGTH] == 'i')
		return (ft_printf_integer(flags, fw_precision, printed_chars, args));
	if (flags[FLAG_TOTAL_NO + LENGTH_MOD_LENGTH] == 'u')
		return (ft_printf_unisgned10(flags,
				fw_precision, printed_chars, args));
	if (flags[FLAG_TOTAL_NO + LENGTH_MOD_LENGTH] == 'x')
		return (ft_printf_base16(flags, fw_precision, printed_chars, args));
	if (flags[FLAG_TOTAL_NO + LENGTH_MOD_LENGTH] == 'X')
		return (ft_printf_base16up(flags, fw_precision, printed_chars, args));
	return (1);
}

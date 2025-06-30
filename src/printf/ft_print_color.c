/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:07:09 by asanz-ra          #+#    #+#             */
/*   Updated: 2025/06/30 17:06:00 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_extended.h"
#include "ft_printf.h"

int	start_color(int color)
{
	char	*color_str;

	if (color == 1)
		color_str = "\e[91m";
	else if (color == 2)
		color_str = "\e[92m";
	else if (color == 3)
		color_str = "\e[93m";
	else if (color == 4)
		color_str = "\e[94m";
	else if (color == 5)
		color_str = "\e[95m";
	else if (color == 6)
		color_str = "\e[96m";
	else if (color == 7)
		color_str = "\e[97m";
	else
		color_str = "";
	return (ft_printf(color_str));
}

int	end_color(void)
{
	char	*remove_colour;

	remove_colour = "\e[0m";
	return (ft_printf(remove_colour));
}

//Prints the passed str in the selected color.
//color can be:
// 1	Red
// 2	Green
// 3	Yellow
// 4	Blue
// 5	Purple
// 6	Cyan
// 7	White
//Other - no color
int	ft_printf_color(int color, const char *format, ...)
{
	size_t	main_iterator;
	int		printed_chars;
	va_list	arguments;

	main_iterator = 0;
	printed_chars = start_color(color);
	va_start(arguments, format);
	while ('\0' != format[main_iterator])
	{
		if (format[main_iterator] != '%')
			print_char_no_conversion(format, &main_iterator, &printed_chars);
		else if (format_parser(format, &main_iterator, &printed_chars,
				arguments) < 0)
		{
			end_color();
			return (-1);
		}
	}
	va_end(arguments);
	printed_chars += end_color();
	return (printed_chars);
}

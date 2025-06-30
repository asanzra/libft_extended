/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_letter_fields.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:45:19 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/12/12 21:20:35 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	assign_flags(const char *format, size_t *format_index, char *flags);
void	length_mod_parser(char *result, const char *format, size_t *index);

int	length_mod_conversion_parser(char *result, const char *format,
		size_t *index)
{
	length_mod_parser(result, format, index);
	if ('c' != format[*index] && 's' != format[*index] && 'p' != format[*index]
		&& 'd' != format[*index] && 'i' != format[*index]
		&& 'u' != format[*index] && 'x' != format[*index]
		&& 'X' != format[*index] && '%' != format[*index])
		return (-1);
	result[FLAG_TOTAL_NO + LENGTH_MOD_LENGTH] = format[*index];
	(*index)++;
	return (1);
}

void	length_mod_parser(char *result, const char *format, size_t *index)
{
	if ('h' == format[*index] || 'l' == format[*index] || 'q' == format[*index]
		|| 'L' == format[*index] || 'j' == format[*index]
		|| 'z' == format[*index] || 'Z' == format[*index]
		|| 't' == format[*index])
	{
		result[FLAG_TOTAL_NO] = format[*index];
		(*index)++;
		if ('h' == format[*index] && 'h' == format[(*index) - 1])
		{
			result[1 + FLAG_TOTAL_NO] = format[*index];
			(*index)++;
		}
		else if ('l' == format[*index] && 'l' == format[(*index) - 1])
		{
			result[1 + FLAG_TOTAL_NO] = format[*index];
			(*index)++;
		}
		else
			result[1 + FLAG_TOTAL_NO] = '-';
	}
	else
	{
		result[FLAG_TOTAL_NO] = '-';
		result[1 + FLAG_TOTAL_NO] = '-';
	}
}

//	The character % is followed by zero or more flags
void	flag_parser(const char *format, size_t	*format_index, char *flags)
{
	size_t	flag_index;

	flag_index = 0;
	while (flag_index < FLAG_TOTAL_NO)
	{
		flags[flag_index] = 0;
		flag_index++;
	}
	assign_flags(format, format_index, flags);
}

void	assign_flags(const char *format, size_t *format_index, char *flags)
{
	char	index_char;

	index_char = format[(*format_index)];
	while ('\0' != index_char && ('#' == index_char || '0' == index_char
			|| '-' == index_char || ' ' == index_char || '+' == index_char
			|| '\'' == index_char || 'I' == index_char))
	{
		if ('#' == index_char)
			flags[0] = 1;
		if ('0' == index_char)
			flags[1] = 1;
		if ('-' == index_char)
			flags[2] = 1;
		if (' ' == index_char)
			flags[3] = 1;
		if ('+' == index_char)
			flags[4] = 1;
		if ('\'' == index_char)
			flags[5] = 1;
		if ('I' == index_char)
			flags[6] = 1;
		(*format_index)++;
		index_char = format[(*format_index)];
	}
}

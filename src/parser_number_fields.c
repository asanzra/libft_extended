/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_number_fields.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:38:00 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/12/12 20:48:13 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fetch_int_from_digits_and_move_index(const char *format, size_t *f_index);

////TODO: manage * and return corresponding things
//		An optional decimal digit string (with nonzero first digit)
//    specifying a minimum field width.  If the converted value has
//    fewer characters than the field width, it will be padded with
//    spaces on the left (or right, if the left-adjustment flag has
//    been given).  Instead of a decimal digit string one may write "*"
//    or "*m$" (for some decimal integer m) to specify that the field
//    width is given in the next argument, or in the m-th argument,
//    respectively, which must be of type int.  A negative field width
//    is taken as a '-' flag followed by a positive field width.  In no
//    case does a nonexistent or small field width cause truncation of
//    a field; if the result of a conversion is wider than the field
//    width, the field is expanded to contain the conversion result.
int	field_width_parser(const char *format, size_t *format_index)
{
	int		field_width;

	if ('*' == format[(*format_index)])
	{
		return (0);
	}
	if (!ft_isdigit(format[(*format_index)]) || '0' == format[(*format_index)])
		return (0);
	field_width = fetch_int_from_digits_and_move_index(format, format_index);
	return (field_width);
}

////TODO: manage * and return corresponding things
// 		An optional precision, in the form of a period ('.')  followed by
//    an optional decimal digit string.  Instead of a decimal digit
//    string one may write "*" or "*m$" (for some decimal integer m) to
//    specify that the precision is given in the next argument, or in
//    the m-th argument, respectively, which must be of type int.  If
//    the precision is given as just '.', the precision is taken to be
//    zero.  A negative precision is taken as if the precision were
//    omitted.  This gives the minimum number of digits to appear for
//    d, i, o, u, x, and X conversions, the number of digits to appear
//    after the radix character for a, A, e, E, f, and F conversions,
//    the maximum number of significant digits for g and G conversions,
//    or the maximum number of characters to be printed from a string
//    for s and S conversions.
int	precision_parser(const char *format, size_t *format_index)
{
	int		precision;

	if ('.' != format[(*format_index)])
		return (-1);
	(*format_index)++;
	if ('*' == format[(*format_index)])
	{
		return (-1);
	}
	if (format[(*format_index)] == '-')
	{
		(*format_index)++;
		fetch_int_from_digits_and_move_index(format, format_index);
		return (-1);
	}
	if (!ft_isdigit(format[(*format_index)]))
		return (0);
	precision = fetch_int_from_digits_and_move_index(format, format_index);
	return (precision);
}

int	fetch_int_from_digits_and_move_index(const char *format, size_t *f_index)
{
	size_t	last_index;
	int		result;
	char	*editable_format;

	editable_format = ft_strdup(format);
	last_index = *f_index;
	while (ft_isdigit(format[last_index + 1]))
		last_index++;
	editable_format[last_index + 1] = '\0';
	result = ft_atoi(editable_format + (*f_index));
	free(editable_format);
	*f_index = last_index + 1;
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:55:16 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/12/14 23:31:12 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*manage_flags(char *flags_len_m_conv, char *int_str);
int		print_null_ptr(int *printed_chars);

////TODO: Use flags, length mod. and precision
// Used flag - and 0
// Used flag . (dont apply)
int	ft_printf_pointer(char *flags_len_m_conv, int *fw_precision,
			int *printed_chars, va_list args)
{
	char				*int_str;
	int					bytes_printed;
	unsigned long long	ptr;

	flags_len_m_conv[0] = 1;
	bytes_printed = 0;
	ptr = va_arg(args, unsigned long long);
	if (ptr == (unsigned long long) NULL)
		return (print_null_ptr(printed_chars));
	int_str = ft_itoa_unsigned_base_long(ptr, "0123456789abcdef");
	int_str = manage_flags(flags_len_m_conv, int_str);
	if (int_str == NULL)
		return (-1);
	bytes_printed = print_str_fw(int_str, fw_precision, flags_len_m_conv);
	free(int_str);
	if (bytes_printed == -1)
		return (-1);
	(*printed_chars) += bytes_printed;
	fw_precision++;
	return (1);
}

char	*manage_flags(char *flags_len_m_conv, char *int_str)
{
	char	*result;
	size_t	dstsize;
	char	*prefix;

	prefix = "0x";
	if (flags_len_m_conv[0] != 1 || int_str == 0)
		return (int_str);
	dstsize = ft_strlen(prefix) + ft_strlen(int_str) + 1;
	result = (char *) malloc(dstsize);
	if (result == 0)
		return (int_str);
	ft_strlcpy(result, prefix, dstsize);
	ft_strlcat(result, int_str, dstsize);
	free(int_str);
	return (result);
}

int	print_null_ptr(int *printed_chars)
{
	if (print_str("(nil)") == -1)
		return (-1);
	(*printed_chars) += 5;
	return (1);
}

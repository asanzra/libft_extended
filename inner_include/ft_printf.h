/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:52:51 by asanz-ra          #+#    #+#             */
/*   Updated: 2025/06/30 17:03:11 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# define FLAG_TOTAL_NO 7
# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# define LENGTH_MOD_LENGTH 2
# define CONVERSION_LENGTH 1
//Include common libraries to whole project
# include "lib_extended.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

//Functions
int		print_char(char c);
void	ft_strlcat_no_minus(char *new_str, char *str, size_t dstsize);
int		print_str(const char *str);
char	*ft_unsigned_itoa(unsigned int n);
void	flag_parser(const char *format, size_t	*format_index, char *flags);
int		field_width_parser(const char *format, size_t *format_index);
int		precision_parser(const char *format, size_t *format_index);
int		length_mod_conversion_parser(char *result,
			const char *format, size_t *index);
int		ft_printf_percent(char *flags_len_m_conv, int *fw_precision,
			int *printed_chars, va_list args);
int		ft_printf_char(char *flags_len_m_conv, int *fw_precision,
			int *printed_chars, va_list args);
int		ft_printf_string(char *flags_len_m_conv, int *fw_precision,
			int *printed_chars, va_list args);
int		ft_printf_pointer(char *flags_len_m_conv, int *fw_precision,
			int *printed_chars, va_list args);
int		ft_printf_integer(char *flags_len_m_conv, int *fw_precision,
			int *printed_chars, va_list args);
int		ft_printf_unisgned10(char *flags_len_m_conv, int *fw_precision,
			int *printed_chars, va_list args);
int		ft_printf_base16(char *flags_len_m_conv, int *fw_precision,
			int *printed_chars, va_list args);
int		ft_printf_base16up(char *flags_len_m_conv, int *fw_precision,
			int *printed_chars, va_list args);
int		print_str_fw(char *str, int *fw, char *flags_len_m_conv);
int		print_char_fw(char *str, int *fw_prec, char *flags_len_m_conv);
int		print_str_precision(char *str, int precision, char *flags_len_m_conv);
int		remove_starting_hex_special(char **str, char *flags_len_m_conv);
int		add_starting_hex_special(char **new_str, char flag_is_neg_hex,
			size_t dstsize);
void	add_positive_sign_for_d_i(char *prefix, char **int_str);
//Basic printf and printf_color
int		format_parser(const char *format, size_t *format_index,
			int *printed_chars, va_list arguments);
int		conversion_map_redirect(char *flags,
			int *fw_precision, int *printed_chars, va_list args);
void	print_char_no_conversion(const char *format,
			size_t *main_iterator, int *printed_chars);

#endif
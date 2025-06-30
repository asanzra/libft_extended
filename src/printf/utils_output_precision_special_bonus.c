/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_output_precision_special_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:42:02 by asanz-ra          #+#    #+#             */
/*   Updated: 2024/12/15 00:04:12 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	remove_starting_hex_special(char **str, char *flags_len_m_conv)
{
	char	*temp;
	size_t	temp_size;

	temp_size = ft_strlen((*str)) - 2 + 1;
	if ((flags_len_m_conv[9] == 'x' || flags_len_m_conv[9] == 'X')
		&& flags_len_m_conv[0] == 1)
	{
		temp = (char *) malloc(temp_size);
		if (temp == 0)
			return (-1);
		ft_strlcpy(temp, (*str), temp_size);
		free(*str);
		(*str) = temp;
		return (1);
	}
	else
		return (1);
}

int	add_starting_hex_special(char **new_str, char flag_is_neg_hex,
	size_t dstsize)
{
	char	*prefix;

	if (flag_is_neg_hex > -1)
		return (1);
	if ((*new_str) == 0)
		return (-1);
	if (flag_is_neg_hex == -1)
		prefix = "0x";
	else
		prefix = "0X";
	ft_strlcpy((*new_str), prefix, dstsize);
	return (1);
}

void	add_positive_sign_for_d_i(char *prefix, char **int_str)
{
	char	*temp;
	size_t	temp_size;

	temp_size = 1 + 1 + ft_strlen((*int_str));
	if ((*int_str) == 0)
		return ;
	temp = (char *) malloc(temp_size);
	if (temp == 0)
		return ;
	ft_strlcpy(temp, prefix, temp_size);
	ft_strlcat(temp, (*int_str), temp_size);
	free(*int_str);
	(*int_str) = temp;
}

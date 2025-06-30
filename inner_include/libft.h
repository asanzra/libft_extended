/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:26:22 by asanz-ra          #+#    #+#             */
/*   Updated: 2025/06/30 15:26:46 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

//itoa_base exported funcs for itoa_base_long -------------------
int		wrong_base(char *base, int base_size);
char	*alloc_str_rev_end_lim(unsigned long long *digits, char *base, int lim);
//---------------------------------------------------------------

#endif
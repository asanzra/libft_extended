/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:07:09 by asanz-ra          #+#    #+#             */
/*   Updated: 2025/02/04 18:29:47 by asanz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_extended.h"

//Prints the passed str in the optn color, followed by a newline if newline==1.
//optn can be:
//1 - Light Red
//2 - Light Green
//Other - no color
int	ft_print_color(const char *str, int optn, int newline)
{
	int		count;
	char	*light_red;
	char	*light_green;
	char	*remove_colour;

	light_red = "\e[91m";
	light_green = "\e[92m";
	remove_colour = "\e[0m";
	count = 0;
	if (optn == 1)
		count += ft_printf(light_red);
	if (optn == 2)
		count += ft_printf(light_green);
	count += ft_printf(str);
	count += ft_printf(remove_colour);
	if (newline == 1)
		count += ft_printf("\n");
	return (count);
}

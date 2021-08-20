/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:14:21 by jvictor-          #+#    #+#             */
/*   Updated: 2021/08/20 20:25:28 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	intlen(int c)
{
	size_t	i;

	i = 0;
	if (c == 0)
		return (1);
	while (c)
	{
		c /= 10;
		i++;
	}
	return (i);
}

size_t	print_digit(int c)
{
	unsigned int	uint_c;
	size_t			is_negative;

	is_negative = 0;
	if (c < 0)
	{
		is_negative++;
		print_putchar('-');
		uint_c = c * -1;
	}
	else
		uint_c = c;
	if (uint_c >= 10)
		print_digit(uint_c / 10);
	print_putchar((char)(uint_c % 10) + 48);
	return (intlen(uint_c) + is_negative);
}

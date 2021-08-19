/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 22:05:53 by jvictor-          #+#    #+#             */
/*   Updated: 2021/08/18 22:37:59 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	size_t	unsignedintlen(unsigned int c)
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

size_t	print_unsigned(unsigned int c)
{
	if (c >= 10)
		print_digit(c / 10);
	print_putchar((char)(c % 10) + 48);
	return (unsignedintlen(c));
}

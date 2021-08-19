/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:26:11 by jvictor-          #+#    #+#             */
/*   Updated: 2021/08/18 22:35:36 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	size_t	hexalen(size_t arg)
{
	size_t	i;

	i = 0;
	if (!arg)
		return (1);
	while (arg)
	{
		arg /= 16;
		i++;
	}
	return (i);
}

size_t	print_pointer(size_t arg)
{
	size_t	hexalength;
	size_t	index;
	char	*hexa;
	char	*base;

	hexalength = hexalen(arg);
	index = hexalength;
	base = "0123456789abcdef";
	hexa = ft_calloc(hexalength + 2, sizeof(char));
	if (!hexa)
		return (0);
	hexa[0] = '0';
	hexa[1] = 'x';
	while (index)
	{
		hexa[--index + 2] = base[arg % 16];
		arg /= 16;
	}
	write(1, hexa, hexalength + 2);
	free(hexa);
	return (hexalength + 2);
}

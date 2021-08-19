/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:46:03 by jvictor-          #+#    #+#             */
/*   Updated: 2021/08/18 22:20:13 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *print, ...)
{
	size_t	amount;
	va_list	args;

	amount = 0;
	va_start(args, print);
	while (*print)
	{
		if (*print == '%' && ft_strchr("cspduixX%", *(print + 1)))
			amount += print_specifier(args, *++print);
		else
			amount += write(1, &(*print), 1);
		print++;
	}
	va_end(args);
	return (amount);
}

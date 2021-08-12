/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:14:21 by jvictor-          #+#    #+#             */
/*   Updated: 2021/08/11 22:08:05 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t  intlen(int c)
{
    size_t i;

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

size_t  print_digit(int c)
{
    size_t is_negative;

    is_negative = 0;
    if (c < 0)
    {
        is_negative++;
        print_putchar('-');
        c *= -1;
    }
    if (c >= 10)
        print_digit(c / 10);
    print_putchar((char)(c % 10) + 48);
    return (intlen(c) + is_negative);
}

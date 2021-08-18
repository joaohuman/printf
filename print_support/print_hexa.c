/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:07:49 by jvictor-          #+#    #+#             */
/*   Updated: 2021/08/17 21:59:22 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	hexalen(unsigned int hex)
{
    size_t	i;

    i = 0;
    if (!hex)
        return (1);
    while (hex)
    {
        hex /= 16;
        i++;
    }
    return (i);
}

size_t  print_hexa(unsigned int hex, char c)
{
    size_t  hexalenght;
    int     index;
    char    *base;
    char    *hexa;

    hexalenght = hexalen(hex);
    index = hexalenght;
    base = "0123456789abcdef";
    if (c == 'X')
        base = "0123456789ABCDEF";
    hexa = ft_calloc(hexalenght, sizeof(char));
    if (!hexa)
        return (0);
    while (index)
    {
        hexa[--index] = base[hex % 16];
        hex /= 16;
    }
    write(1, hexa, hexalenght);
    free(hexa);
    return (hexalenght);
}

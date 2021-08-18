/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:11:40 by jvictor-          #+#    #+#             */
/*   Updated: 2021/08/12 21:37:25 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t  print_specifier(va_list args, char c)
{
    size_t count;
    t_types types;

    count = 0;
    if (c == 'c')
        count = print_putchar(types.c_char = va_arg(args, char));
    else if (c == 's')
        count = print_putstr(types.s_string = va_arg(args, char *));    
    else if (c == 'p')
        count = print_pointer(types.p_hex = va_arg(args, size_t));
    else if (c == 'd' || c == 'i')
        count = print_digit(types.di_int = va_arg(args, int));
    else if (c == 'u')
        count = print_unsigned(types.u_uint = va_arg(args, unsigned int));
    else if (c == 'x' || c == 'X')
        count = print_hexa(types.xX_uint = va_arg(args, unsigned int), c);
    else if(c == '%')
        count = print_putchar(c);
    return (count);
}
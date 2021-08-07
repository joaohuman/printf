/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:04:57 by jvictor-          #+#    #+#             */
/*   Updated: 2021/08/07 20:28:26 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

typedef struct s_types
{
    char            c_char;
    char            *s_string;
    size_t          p_hex;
    int             di_int;
    unsigned int    u_uint;
    unsigned int    xX_uint;
} t_types;

int ft_printf(const char *, ...);

#endif
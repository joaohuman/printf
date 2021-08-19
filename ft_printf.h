/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:04:57 by jvictor-          #+#    #+#             */
/*   Updated: 2021/08/18 22:20:11 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

typedef struct s_types
{
	char			c_char;
	char			*s_string;
	size_t			p_hex;
	int				di_int;
	unsigned int	u_uint;
	unsigned int	xX_uint;
}	t_types;

int		ft_printf(const char *print, ...);

size_t	print_specifier(va_list args, char c);
size_t	print_putchar(char c);
size_t	print_putstr(char *c);
size_t	print_digit(int c);
size_t	print_unsigned(unsigned int c);
size_t	print_hexa(unsigned int hex, char c);

#endif
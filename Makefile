# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvictor- <jvictor-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 20:30:41 by jvictor-          #+#    #+#              #
#    Updated: 2021/08/19 21:39:50 by jvictor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= clang

BIN		= ${FILES:%.c=%.o}

CFLAGS	= -Wall -Wextra -Werror

FILES	=	ft_printf.c \
			print_digit.c \
			print_hexa.c \
			print_pointer.c \
			print_putchar.c \
			print_putstr.c \
			print_specifier.c \
			print_unsigned.c \

all: ${NAME}

${NAME} : ${BIN} libft
	cp ./libft/libft.a $(NAME)
	ar -rcs $(NAME) $(BIN)

%.o: %.c
	${CC} -c ${CFLAGS} $< -o $@

libft:
	make all -C ./libft

clean: libclean
	rm -f ${BIN}

fclean: clean libfclean
	rm -f ${NAME}

libclean:
	make clean -C ./libft

libfclean:
	make fclean -C ./libft

re: fclean all libftre

libftre:
	make re -C ./libft

.PHONY: all libft clean fclean libclean libfclean re libftre

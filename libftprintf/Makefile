# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msuter <msuter@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/18 21:42:01 by msuter            #+#    #+#              #
#    Updated: 2025/10/18 21:52:33 by msuter           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
CC = gcc
CFLAG = -Wall -Werror -Wextra

SRCS = ft_putchar.c ft_putnbr_base_maj.c ft_putstr.c hexa_opti.c modif_putnbr.C

OBJS = $(SRCS:.c=.o)

all : $(NAME)

(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

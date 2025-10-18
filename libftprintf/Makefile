# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msuter <msuter@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/18 21:42:01 by msuter            #+#    #+#              #
#    Updated: 2025/10/18 22:29:59 by msuter           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_putchar.c ft_putnbr_base_maj.c ft_putstr.c hexa_opti.c \
		modif_putnbr.c ft_printf.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(LIBFT):
	make -C $(LIBFT_DIR)

all : $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)
%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

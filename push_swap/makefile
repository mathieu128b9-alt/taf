# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msuter <msuter@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 17:56:42 by msuter            #+#    #+#              #
#    Updated: 2025/11/07 19:35:06 by msuter           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_push_swap.c
OBJS = $(SRCS:.c=.o)

PRINTF_DIR = libftprintf
PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT = $(PRINTF_DIR)/libft/libft.a

INCLUDES = -I$(PRINTF_DIR) -I$(PRINTF_DIR)/libft

all: $(PRINTF) $(NAME)

$(NAME): $(OBJS) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR) all

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all


.PHONY: all clean fclean re
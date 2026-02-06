# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 15:55:54 by msuter            #+#    #+#              #
#    Updated: 2026/02/06 13:19:56 by mathieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c utils.c

OBJS = $(SRCS:.c=.o)

PRINTF	= libftprintf/libftprintf.a
LIBFT	= libftprintf/libft/libft.a

INCLUDES	= -I. -Ilibftprintf -Ilibftprintf/libft

all: $(PRINTF) $(NAME)
	clear

$(NAME): $(OBJS) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(PRINTF):
	$(MAKE) -C libftprintf
	clear

clean:
	rm -f $(OBJS)
	$(MAKE) -C libftprintf clean
	clear

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libftprintf fclean
	clear

re: fclean all

.PHONY: all clean fclean re
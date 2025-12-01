# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msuter <msuter@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/30 10:51:46 by msuter            #+#    #+#              #
#    Updated: 2025/12/01 01:38:21 by msuter           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract_ol
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = 

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a
MINILIBX = minilibx/libmlx_Linux.a

INCLUDES = -I. -Ilibft -Iminilibx

OTHER_LINK = -lXext -lX11 -lm -lz

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(OTHER_LINK) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msuter <msuter@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/30 10:51:46 by msuter            #+#    #+#              #
#    Updated: 2025/12/04 17:52:44 by msuter           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract_ol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2

THREAD_LINIK = -pthread

SRCS = main.c error.c buttons.c pixel.c d_segment.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx
MLX = $(MLX_DIR)/libmlx_Linux.a

INCLUDES = -I. -I$(LIBFT_DIR) -I$(MLX_DIR)

OTHER_LINK = -lXext -lX11 -lm -lz

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(OTHER_LINK) $(THREAD_LINIK) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
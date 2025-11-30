# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msuter <msuter@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 17:56:42 by msuter            #+#    #+#              #
#    Updated: 2025/11/30 12:49:39 by msuter           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= utils/push.c utils/reverse_rotate.c utils/rotate.c \
			utils/swap.c calculate_min_move.c finale_move.c \
			ft_push_swap.c indice.c is_in_lis.c lis.c verification.c

OBJS	= $(SRCS:.c=.o)

PRINTF_DIR	= libftprintf
PRINTF	= $(PRINTF_DIR)/libftprintf.a
LIBFT	= $(PRINTF_DIR)/libft/libft.a

INCLUDES	= -I. -I$(PRINTF_DIR) -I$(PRINTF_DIR)/libft

all: $(PRINTF) $(NAME)

$(NAME): $(OBJS) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) -o $(NAME)

# Règle explicite pour compiler les .c en .o avec les includes
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
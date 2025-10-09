NAME = libft.a
SRCS = ft_strlen.c ft_memcpy.c ft_strdup.c ft_atoi.c ft_isalpha.c \
		ft_isdigit.c ft_memmove.c ft_calloc.c ft_substr.c ft_strjoin.c \
		ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_putendl_fd.c \
		ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_strnstr.c ft_strchr.c \
		ft_strrchr.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
		ft_tolower.c ft_itoa.c ft_split.c ft_strtrim.c ft_strmapi.c \
		ft_striteri.c ft_memset.c ft_bzero.c ft_memchr.c ft_memcmp.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

ft_toupper.o : ft_toupper.c libft.h
	cc -Wall -Wextra -Werror -c ft_toupper.c -o ft_toupper.o

ft_tolower.o : ft_tolower.c libft.h
	cc -Wall -Wextra -Werror -c ft_tolower.c -o ft_tolower.o

ft_substr.o  :ft_substr.c libft.h
	cc -Wall -Wextra -Werror -c ft_substr.c -o ft_substr.o

ft_strtrim.o : ft_strtrim.c libft.h
	cc -Wall -Wextra -Werror -c ft_strtrim.c -o ft_strtrim.o

ft_strrchr.o : ft_strrchr.c libft.h
	cc -Wall -Wextra -Werror -c ft_strrchr.c -o ft_strrchr.o

ft_strnstr.o : ft_strnstr.c libft.h
	cc -Wall -Wextra -Werror -c ft_strnstr.c -o ft_strnstr.o

ft_strncmp.o : ft_strncmp.c libft.h
	cc -Wall -Wextra -Werror -c ft_strncmp.c -o ft_strncmp.o

ft_strmapi.o :ft_strmapi.c libft.h
	cc -Wall -Wextra -Werror -c ft_strmapi.c -o ft_strmapi.o

ft_strlen.o : ft_strlen.c libft.h
	cc -Wall -Wextra -Werror -c ft_strlen.c -o ft_strlen.o

ft_strlcpy.o : ft_strlcpy.c libft.h
	cc -Wall -Wextra -Werror -c ft_strlcpy.c -o ft_strlcpy.o

ft_strlcat.o : ft_strlcat.c libft.h
	cc -Wall -Wextra -Werror -c ft_strlcat.c -o ft_strlcat.o

ft_strjoin.o :ft_strjoin.c libft.h
	cc -Wall -Wextra -Werror -c ft_strjoin.c -o ft_strjoin.o

ft_striteri.o : ft_striteri.c libft.h
	cc -Wall -Wextra -Werror -c ft_striteri.c -o ft_striteri.o

ft_strdup.o : ft_strdup.c libft.h
	cc -Wall -Wextra -Werror -c ft_strdup.c -o ft_strdup.o

ft_strchr.o : ft_strchr.c libft.h
	cc -Wall -Wextra -Werror -c ft_strchr.c -o ft_strchr.o

ft_split.o : ft_split.c libft.h
	cc -Wall -Wextra -Werror -c ft_split.c -o ft_split.o

ft_putstr_fd.o :ft_putstr_fd.c libft.h
	cc -Wall -Wextra -Werror -c ft_putstr_fd.c -o ft_putstr_fd.o

ft_putnbr_fd.o : ft_putnbr_fd.c libft.h
	cc -Wall -Wextra -Werror -c ft_putnbr_fd.c -o ft_putnbr_fd.o

ft_putendl_fd.o : ft_putendl_fd.c libft.h
	cc -Wall -Wextra -Werror -c ft_putendl_fd.c -o ft_putendl_fd.o

ft_putchar_fd.o : ft_putchar_fd.c libft.h
	cc -Wall -Wextra -Werror -c ft_putchar_fd.c -o ft_putchar_fd.o

ft_memset.o : ft_memset.c libft.h
	cc -Wall -Wextra -Werror -c ft_memset.c -o ft_memset.o

ft_memmove.o : ft_memmove.c libft.h
	cc -Wall -Wextra -Werror -c ft_memmove.c -o ft_memmove.o

ft_memcpy.o : ft_memcpy.c libft.h
	cc -Wall -Wextra -Werror -c ft_memcpy.c -o ft_memcpy.o

ft_memcmp.o : ft_memcmp.c libft.h
	cc -Wall -Wextra -Werror -c ft_memcmp.c -o ft_memcmp.o

ft_memchr.o :ft_memchr.c libft.h
	cc -Wall -Wextra -Werror -c ft_memchr.c -o ft_memchr.o

ft_itoa.o :ft_itoa.c libft.h
	cc -Wall -Wextra -Werror -c ft_itoa.c -o ft_itoa.o

ft_isprint.o : ft_isprint.c libft.h
	cc -Wall -Wextra -Werror -c ft_isprint.c -o ft_isprint.o

ft_isdigit.o : ft_isdigit.c libft.h
	cc -Wall -Wextra -Werror -c ft_isdigit.c -o ft_isdigit.o

ft_isascii.o : ft_isascii.c libft.h
	cc -Wall -Wextra -Werror -c ft_isascii.c -o ft_isascii.o

ft_isalpha.o : ft_isalpha.c libft.h
	cc -Wall -Wextra -Werror -c ft_isalpha.c -o ft_isalpha.o

ft_isalnum.o :ft_isalnum.c libft.h
	cc -Wall -Wextra -Werror -c ft_isalnum.c -o ft_isalnum.o

ft_calloc.o :ft_calloc.c libft.h
	cc -Wall -Wextra -Werror -c ft_calloc.c -o ft_calloc.o

ft_bzero.o : ft_bzero.c libft.h
	cc -Wall -Wextra -Werror -c ft_bzero.c -o ft_bzero.o

ft_atoi.o :ft_atoi.c libft.h
	cc -Wall -Wextra -Werror -c ft_atoi.c -o ft_atoi.o


NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_isascii.c ft_strchr.c ft_strrchr.c \
	   ft_isdigit.c ft_tolower.c ft_strnstr.c \
	   ft_isprint.c ft_strdup.c ft_toupper.c \
	   ft_atoi.c ft_memchr.c ft_strlcat.c \
	   ft_bzero.c ft_memcmp.c \
	   ft_strlcpy.c ft_calloc.c ft_memcpy.c \
	   ft_strlen.c ft_isalnum.c ft_memmove.c \
	   ft_strncmp.c ft_isalpha.c ft_memset.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


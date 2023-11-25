# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manufern <manufern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 20:45:56 by manufern          #+#    #+#              #
#    Updated: 2023/11/25 19:24:44 by manufern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS	=  ft_printf.c\
            ft_printf_aux.c

LIB = ar rcs

OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME):    $(OBJS)
	$(CC) -c $(CFLAGS) $(SRCS)
	$(LIB) $(NAME) $(OBJS)

clean:			
	rm  -f *.o

fclean:
	$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
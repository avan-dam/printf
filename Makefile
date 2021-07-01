# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avan-dam <avan-dam@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/31 16:32:12 by avan-dam      #+#    #+#                  #
#    Updated: 2021/07/01 11:32:34 by ambervandam   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	printf_c.c \
		printf_di.c \
		printf_s.c \
		printf_mainbit.c \
		printf_p.c \
		printf_u.c \
		printf_xx.c

LIB = $(SRCS:.c=.o)

INCLUDE = printf.h

all: $(NAME)

$(NAME): $(LIB)
	ar rc $(NAME) $(LIB) $(INCLUDE)
	ranlib $(NAME)

%.o: %.c
	gcc -o $@ -c $< -Wall -Wextra -Werror

clean:
	/bin/rm -f $(LIB)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

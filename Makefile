# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avan-dam <avan-dam@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/31 16:32:12 by avan-dam       #+#    #+#                 #
#    Updated: 2020/02/03 14:53:37 by avan-dam      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = printf_c.c printf_di.c printf_s.c printf_mainbit.c printf_p.c \
printf_u.c printf_xx.c

LIB = printf_c.o printf_di.o printf_s.o printf_mainbit.o printf_p.o  \
printf_u.o printf_xx.o

INCLUDE = printf_header.h

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

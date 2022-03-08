# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lemmon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 17:49:10 by lemmon            #+#    #+#              #
#    Updated: 2021/12/01 17:49:17 by lemmon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = libftprintf.a

SRCS   = ft_printf.c ft_printf_utils.c ft_printf_write.c

HEADER   = ft_printf.h

CFLAGS = -Wall -Werror -Wextra
CC     = gcc
RM     = rm -f

OBJ    = $(patsubst %.c, %.o, $(SRCS))

.PHONY: all clean fclean re bonus

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ) $(HEADER)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
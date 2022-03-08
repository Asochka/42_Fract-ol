NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEAD_FILE = includes/ft_printf.h

SRCS =	./srcs/ft_eval_format.c \
		./srcs/ft_print_char.c \
		./srcs/ft_print_lowhex.c \
		./srcs/ft_print_upphex.c \
		./srcs/ft_print_point.c \
		./srcs/ft_print_str.c \
		./srcs/ft_print_int.c \
		./srcs/ft_print_unint.c \
		./srcs/ft_printf.c \
		./srcs/ft_putnbr.c \
		./srcs/ft_putnbr_un.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c $(HEAD_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
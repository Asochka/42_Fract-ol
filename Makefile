NAME  = fractol

LIBMLX_DIR = ./minilibx-linux
CC		      = cc
CFLAGS		  = -Wall -Wextra -Werror 
LDFLAGS		  =	 -L$(LIBMLX_DIR) -lmlx -framework OpenGL -framework Appkit -fsanitize=address
RM			  =	rm -f

.PHONY: all clean fclean re bonus

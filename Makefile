NAME  = fractol

SRCS_DIR      = ./srcs/
OBJS_DIR      = ./objs/
LIBMLX_DIR    = ./mlx/
PRINTFT_DIR   = ./ft_printf/
HEAD_DIR      = ./includes/
HEAD_LIST	  = fractol.h

LIBMLX        = $(addprefix $(LIBMLX_DIR), libmlx.a)
LIBFTPRINTF   = $(addprefix $(PRINTFT_DIR), libftprintf.a)
HEAD          = $(addprefix $(HEAD_DIR), $(HEAD_LIST))

SRCS_FILES    = main.c utils.c hooks.c fractal.c arg_julia.c
SRCS          = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS          = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))

CC		      = cc
CFLAGS		  = -Wall -Wextra -Werror 
LDFLAGS		  =	-L$(PRINTFT_DIR) -L$(LIBMLX_DIR) -lmlx -framework OpenGL -framework Appkit
RM			  =	rm -f

.PHONY: all clean fclean re

all: $(LIBMLX) $(LIBFTPRINTF) $(NAME)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(LIBMLX) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(HEAD_DIR) -Imlx -c $< -o $@

$(LIBMLX):
	make -C $(LIBMLX_DIR)

$(LIBFTPRINTF):
	make -C $(PRINTFT_DIR)

$(NAME): $(OBJS)  $(LIBMLX) $(HEAD)
	$(CC) $(OBJS) $(LIBFTPRINTF) -o $@ $(LDFLAGS)
	@echo ""
	@echo "\x1b[1;35m \x1b[1;35m ☆* Makefile is done SUCCESSFULLY! *☆\033[0m"
	@echo ""

clean:
		$(RM) -r $(OBJS_DIR)
		make -C $(LIBMLX_DIR) clean
		make -C $(PRINTFT_DIR) clean

fclean: clean
		$(RM) $(NAME) $(LIBMLX) $(LIBFTPRINTF)
		
re: clean $(OBJS_DIR) fclean all  

NAME  = fractol

SRCS_DIR      = ./srcs/
SRCS_B_DIR    = ./srcs_b/
OBJS_DIR      = ./objs/
OBJS_B_DIR    = ./objs_b/
LIBMLX_DIR    = ./mlx/
PRINTFT_DIR   = ./ft_printf/
HEAD_DIR      = ./includes/
HEAD_LIST	  = fractol.h
HEAD_B_LIST   = fractol_bonus.h

LIBMLX        = $(addprefix $(LIBMLX_DIR), libmlx.a)
LIBFTPRINTF   = $(addprefix $(PRINTFT_DIR), libftprintf.a)
HEAD          = $(addprefix $(HEAD_DIR), $(HEAD_LIST))
HEAD_B        = $(addprefix $(HEAD_DIR), $(HEAD_B_LIST))

SRCS_FILES    = main.c window.c fractals.c hook.c
SRCS_B_FILES  = main_bonus.c window_bonus.c fractals_bonus.c hook_bonus.c
SRCS          = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
SRCS_B        = $(addprefix $(SRCS_B_DIR), $(SRCS_B_FILES))
OBJS          = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))
OBJS_B        = $(addprefix $(OBJS_B_DIR), $(notdir $(SRCS_B:.c=.o)))

CC		      = cc
CFLAGS		  = -Wall -Wextra -Werror 
LDFLAGS		  =	-L$(PRINTFT_DIR) -L$(LIBMLX_DIR) -lmlx -framework OpenGL -framework Appkit -fsanitize=address
RM			  =	rm -f

.PHONY: all clean fclean re bonus

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

bonus:
		@make OBJS="$(OBJS_B)" OBJS_DIR="$(OBJS_B_DIR)" SRCS_DIR="$(SRCS_B_DIR)" HEAD="$(HEAD_B)" all

clean:
		$(RM) -r $(OBJS_DIR) $(OBJS_B_DIR)
		make -C $(LIBMLX_DIR) clean
		make -C $(PRINTFT_DIR) clean

fclean: clean
		$(RM) $(NAME) $(LIBMLX) $(LIBFTPRINTF)
		
re: clean $(OBJS_DIR) fclean all  

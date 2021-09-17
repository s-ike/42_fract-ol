NAME		:= fractol

SRCDIR		:= ./srcs/
SRC			:= main.c \
				color.c \
				draw.c \
				exit.c \
				hooks.c \
				init.c \
				move.c \
				validator.c \
				zoom.c
SRC			:= $(addprefix $(SRCDIR), $(SRC))
OBJ			:= $(SRC:.c=.o)
DEP			:= $(SRC:.c=.d)

INCLUDE 	:= -I./includes/ \
				-I./libft/

LIBDIR		:= ./libft
LIBPATH		:= $(LIBDIR)/libft.a

MLX_DIR		:= ./minilibx-linux
ifeq ($(shell uname),Linux)
MLX_NAME	:= libmlx.a
MLX_FLAGS	:= -lmlx -lXext -lX11 -lm

C_GREEN		:= "\e[32m"
C_DEFAULT	:= "\e[39m"
C_RESET		:= "\e[0m"
else
MLX_NAME	:= libmlx_Darwin.a
MLX_FLAGS	:= -lmlx_Darwin -L/usr/X11/include/../lib -lXext -lX11

C_GREEN		:= "\x1b[32m"
C_DEFAULT	:= "\x1b[39m"
C_RESET		:= "\x1b[0m"
endif
MLX_PATH	:= $(MLX_DIR)/$(MLX_NAME)
INCLUDE		+= -I$(MLX_DIR)

CFLAGS		:= -Wall -Wextra -Werror -MMD -MP
DEBUG		:= -g
ifdef LEAKS
DEBUG2		:=
else
DEBUG2		:= #-fsanitize=address
endif

CC			:= gcc
RM			:= rm -f

.c.o:
			$(CC) $(CFLAGS) $(DEBUG) $(DEBUG2) $(INCLUDE) -c $< -o $@

all:		$(NAME)

$(NAME):	$(LIBPATH) $(MLX_PATH) $(OBJ)
			cp $(MLX_PATH) .
			$(CC) $(CFLAGS) $(OBJ) $(DEBUG) $(DEBUG2) -L. $(MLX_FLAGS) $(LIBPATH) -o $(NAME)
			@echo $(C_GREEN)"=== Make Done ==="$(C_DEFAULT)$(C_REST)

$(LIBPATH):	init
			$(MAKE) -C $(LIBDIR)

$(MLX_PATH):
			$(MAKE) -C $(MLX_DIR)

init:		$(MLX_DIR)
			git submodule update --init

leaks:		$(LIBPATH) $(MLX_PATH)	## For leak check
			$(MAKE) CFLAGS="$(CFLAGS) -D LEAKS=1" LEAKS=TRUE

clean:
			$(MAKE) clean -C $(LIBDIR)
			$(MAKE) clean -C $(MLX_DIR)
			$(RM) $(OBJ) $(DEP)

fclean:		clean
			$(MAKE) fclean -C $(LIBDIR)
			$(RM) $(MLX_NAME)
			$(RM) $(NAME)

re:			fclean $(NAME)

bonus:		$(NAME)

$(MLX_DIR):
			git clone https://github.com/42Paris/minilibx-linux.git

delmlx:
			rm -rf $(MLX_DIR)

-include	$(DEP)

.PHONY:		all clean fclean re bonus
.PHONY:		init leaks mlx delmlx

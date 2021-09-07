NAME		:= fractol

SRCDIR		:= ./srcs/
SRC			:= main.c \
				draw.c \
				exit.c \
				validator.c
SRC			:= $(addprefix $(SRCDIR), $(SRC))
OBJ			:= $(SRC:.c=.o)

INCLUDE 	:= -I./includes/ \
				-I./libft/

LIBDIR		:= ./libft
LIBPATH		:= $(LIBDIR)/libft.a

ifeq ($(shell uname),Linux)
MLX_DIR		:= ./minilibx-linux
MLX_NAME	:= libmlx.a
MLX_FLAGS	:= -lmlx -lXext -lX11 -lm
CFLAGS		:= -Wall -Wextra -Werror -D LINUX

C_GREEN		:= "\e[32m"
C_DEFAULT	:= "\e[39m"
C_RESET		:= "\e[0m"
else
MLX_DIR		:= ./minilibx_mms_20200219
MLX_NAME	:= libmlx.dylib
MLX_FLAGS	:= -lmlx -framework OpenGL -framework AppKit -lz
CFLAGS		:= -Wall -Wextra -Werror

C_GREEN		:= "\x1b[32m"
C_DEFAULT	:= "\x1b[39m"
C_RESET		:= "\x1b[0m"
endif
MLX_PATH	:= $(MLX_DIR)/$(MLX_NAME)
INCLUDE		+= -I$(MLX_DIR)

DEBUG		:= -g
ifdef LEAKS
DEBUG2		:=
else
DEBUG2		:= -fsanitize=address
endif

CC			:= gcc
RM			:= rm -f

.c.o:
			$(CC) $(CFLAGS) $(DEBUG) $(DEBUG2) $(INCLUDE) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBPATH) $(MLX_PATH)
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
			$(RM) $(OBJ)

fclean:		clean
			$(MAKE) fclean -C $(LIBDIR)
			$(RM) $(MLX_NAME)
			$(RM) $(NAME)

re:			fclean $(NAME)

ifeq ($(shell uname),Linux)
$(MLX_DIR):
			git clone https://github.com/42Paris/minilibx-linux.git
else
$(MLX_DIR):
			curl -O https://projects.intra.42.fr/uploads/document/document/4671/minilibx_mms_20200219_beta.tgz
			tar -xvf minilibx_mms_20200219_beta.tgz
endif

delmlx:
			rm -rf $(MLX_DIR)

.PHONY:		all clean fclean re
.PHONY:		init leaks mlx delmlx

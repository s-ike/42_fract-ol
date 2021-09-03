NAME		:= fractol

SRCDIR		:= ./srcs/
SRC			:= $(SRCDIR)main.c
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

DEBUG		:= -g -fsanitize=address
CC			:= gcc
RM			:= rm -f

.c.o:
			$(CC) $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBPATH) $(MLX_PATH)
			cp $(MLX_PATH) .
			$(CC) $(CFLAGS) $(OBJ) $(DEBUG) -L. $(MLX_FLAGS) $(LIBPATH) -o $(NAME)
			@echo $(C_GREEN)"=== Make Done ==="$(C_DEFAULT)$(C_REST)

bonus:		$(BNS_OBJ) $(LIBPATH) $(MLX_PATH)
			cp $(MLX_PATH) .
			$(CC) $(CFLAGS) $(BNS_OBJ) $(DEBUG) -L. $(MLX_FLAGS) $(LIBPATH) -o $(NAME)
			@echo $(C_GREEN)"=== Make Done ==="$(C_DEFAULT)$(C_REST)

$(LIBPATH):
			$(MAKE) -C $(LIBDIR)

$(MLX_PATH):
			$(MAKE) -C $(MLX_DIR)

init:		mlx
			git submodule update --init

clean:
			$(MAKE) clean -C $(LIBDIR)
			$(MAKE) clean -C $(MLX_DIR)
			$(RM) $(OBJ)
			$(RM) $(BNS_OBJ)

fclean:		clean
			$(MAKE) fclean -C $(LIBDIR)
			$(RM) $(MLX_NAME)
			$(RM) $(NAME)

re:			fclean $(NAME)

mlx:
ifeq ($(shell uname),Linux)
			git clone https://github.com/42Paris/minilibx-linux.git
else
			curl -O https://projects.intra.42.fr/uploads/document/document/4671/minilibx_mms_20200219_beta.tgz
			tar -xvf minilibx_mms_20200219_beta.tgz
endif

delmlx:
			rm -rf $(MLX_DIR)

.PHONY:		all clean fclean re bonus
.PHONY:		init mlx delmlx

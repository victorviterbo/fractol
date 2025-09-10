# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:45:22 by vviterbo          #+#    #+#              #
#    Updated: 2025/09/10 13:16:37 by victorviter      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = fractol.c fractals.c hooks.c parsing.c utils.c utils_img.c arg_check.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

CFLAGS = -Wall -Wextra -Werror

CC = cc 

OS := $(shell uname)

ifeq ($(OS), Darwin)
	MLX_PATH = minilibx_opengl/
	INCLUDE = -lm -L $(MLX_PATH) -lmlx -L libft/ -lft -framework OpenGL -framework AppKit
else ifeq ($(OS), Linux)
	MLX_PATH = minilibx-linux/
	INCLUDE = -lm -L $(MLX_PATH) -lmlx -L libft/ -lft -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
endif

all: $(NAME)

clean :
	$(MAKE) -C libft/ fclean
	$(MAKE) -C $(MLX_PATH) clean
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

$(NAME): $(SRCS)
	@$(MAKE) -C libft/ all
	@$(MAKE) -C $(MLX_PATH) all
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDE) -o $(NAME)
	@echo "$(NAME) compiled successfully"

.PHONY: all clean fclean re


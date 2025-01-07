# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:45:22 by vviterbo          #+#    #+#              #
#    Updated: 2024/12/12 15:00:42 by vviterbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c fractals.c hooks.c parsing.c utils.c utils_img.c arg_check.c

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
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

clean_libs : 
	$(MAKE) -C libft/ fclean
	$(MAKE) -C $(MLX_PATH) clean

relibs : clean_libs re

$(NAME):
	$(MAKE) -C libft/ all
	$(MAKE) -C $(MLX_PATH) all
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDE) -o $(NAME)

.PHONY: all clean fclean re bonus


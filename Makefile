# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:45:22 by vviterbo          #+#    #+#              #
#    Updated: 2024/12/11 11:47:04 by vviterbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c fractals.c hooks.c parsing.c utils.c utils_img.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

CFLAGS = -Wall -Wextra -Werror -framework OpenGL -framework AppKit -framework CoreFoundation

CC = gcc

all: $(NAME)

clean :
	$(MAKE) -C libft/ clean
	$(MAKE) -C minilibx_opengl/ clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE) -C libft/ fclean
	rm -f $(NAME)

re : fclean all

$(NAME):
	$(MAKE) -C libft/ all
	$(MAKE) -C minilibx_opengl/ all
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -lm -L minilibx_opengl/ -lmlx -L libft/ -lft 

.PHONY: all clean fclean re bonus

#-Wl,-rpath,$(ORIGIN)/minilibx_opengl/

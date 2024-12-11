# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:45:22 by vviterbo          #+#    #+#              #
#    Updated: 2024/12/11 15:09:19 by vviterbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c fractals.c hooks.c parsing.c utils.c utils_img.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

CFLAGS = -Wall -Wextra -Werror -framework OpenGL -framework AppKit -framework CoreFoundation

CC = cc

all: $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

clean_libs : 
	$(MAKE) -C libft/ fclean
	$(MAKE) -C minilibx_opengl/ clean

relibs : clean_libs re

$(NAME):
	$(MAKE) -C libft/ all
	$(MAKE) -C minilibx_opengl/ all
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -lm -L minilibx_opengl/ -lmlx -L libft/ -lft 

.PHONY: all clean fclean re bonus

#-Wl,-rpath,$(ORIGIN)/minilibx_opengl/

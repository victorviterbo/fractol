# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:45:22 by vviterbo          #+#    #+#              #
#    Updated: 2024/12/10 15:32:35 by vviterbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c fractals.c hooks.c parsing.c utils.c utils_img.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address

CC = gcc

all: $(NAME)

clean :
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C minilibx/ clean
	@rm -f $(OBJS)

fclean : clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(NAME)

re : fclean all

$(NAME):
	@$(MAKE) -C libft/ all
	@$(MAKE) -C minilibx/ all
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -lm -Lminilibx/ -lmlx -L libft/ -lft


.PHONY: all clean fclean re bonus

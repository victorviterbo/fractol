# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:45:22 by vviterbo          #+#    #+#              #
#    Updated: 2024/12/10 12:45:31 by vviterbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c fractals.c hooks.c parsing.c utils.c utils_img.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

$(NAME):
	@$(MAKE) -C libft/ all
	@$(MAKE) -C minilibx/ all
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -lm -Lminilibx/ -lmlx -L libft/ -lft


.PHONY: all clean fclean re bonus

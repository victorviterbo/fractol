# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:45:22 by vviterbo          #+#    #+#              #
#    Updated: 2024/12/03 00:15:12 by vviterbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c fractals.c pt2pxl.c

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
	@$(MAKE) -C libft/ xtra
	@$(MAKE) -C minilibx/ all
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -lm -Lminilibx/ -lmlx -L libft/ -lft


.PHONY: all clean fclean re bonus

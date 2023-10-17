# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 17:54:21 by mhiguera          #+#    #+#              #
#    Updated: 2023/10/17 11:39:49 by mhiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
MLX_FLAGS = -framework OpenGL -framework AppKit
GNL = ./gnl
LIB = ./src/so_long.h
SRC_PATH = ./src/

SRC = map_checker.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(LIB) $(GNL) $(MLX_FLAGS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C ./gnl

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./gnl

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus
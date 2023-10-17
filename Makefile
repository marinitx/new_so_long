# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 17:54:21 by mhiguera          #+#    #+#              #
#    Updated: 2023/10/16 10:07:31 by mhiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src/map_checker.c gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS = $(SRC:.c=.o)
C = gcc -c
FLAGS = -Wall -Wextra -Werror
NAME = so_long
RM =  /bin/rm -f
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(C) -Wall -Wextra -Werror -c $< -o $@

#.SILENT:
$(NAME): $(OBJS)
	$(C) $(FLAGS) $(SRC)
	gcc $(OBJS) $(MLX_FLAGS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
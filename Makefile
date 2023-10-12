# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 17:54:21 by mhiguera          #+#    #+#              #
#    Updated: 2023/10/12 18:53:25 by mhiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = so_long.c gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS = $(SRC:.c=.o)
C = gcc -c
FLAGS = -Wall -Wextra -Werror
NAME = so_long
RM =  /bin/rm -f

%.o: %.c
	$(C) -Wall -Wextra -Werror -Imlx -c $< -o $@

#.SILENT:
$(NAME): $(OBJS)
	$(C) $(FLAGS) $(SRC)
	gcc $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
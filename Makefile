# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 17:54:21 by mhiguera          #+#    #+#              #
#    Updated: 2023/10/01 17:58:27 by mhiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = prueba1.c gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS = $(SRC:.c=.o)
C = gcc -c
FLAGS = -Wall -Wextra -Werror
NAME = hola.a
RM =  /bin/rm -f

#.SILENT:
$(NAME): $(OBJS)
	$(C) $(FLAGS) $(SRC)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
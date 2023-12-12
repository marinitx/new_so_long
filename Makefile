# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 17:54:21 by mhiguera          #+#    #+#              #
#    Updated: 2023/12/12 17:28:32 by mhiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  ./src/so_long.c ./src/map_checker.c ./src/controls.c ./src/img.c ./src/utils.c ./src/map_read.c ./src/check_path.c

OBJS = $(SRC:.c=.o)
GNL_OBJS = $(GNL:.c=.o)
ALL_OBJS = $(OBJS) $(GNL_OBJS)

CC = gcc

CFLAGS = -Wall -Werror -Wextra  -fsanitize=address -g3

MLX = -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = ./libft/
LIBFT_A = libft.a
LIBFT = -L$(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT_A)

GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

NAME = so_long

RM =  /bin/rm -f

all: $(NAME) 

.SILENT: $(ALL_OBJS)

$(NAME): $(ALL_OBJS)
	@make bonus -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(ALL_OBJS) $(MLX) $(LIBFT_DIR)$(LIBFT_A) -o $(NAME)
	

bonus: $(OBJ) $(BONUS_OBJS)
	@$(C) $(FLAGS) $(SRC)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
clean:
	@$(RM) $(OBJS) $(BONUS_OBJS) $(LIBFT)
	@make clean -C $(LIBFT_DIR)
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME) $(BONUS_OBJS) $(OBJS) $(GNL_OBJS)
re: fclean all
.PHONY: all fclean clean re 
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 17:54:21 by mhiguera          #+#    #+#              #
#    Updated: 2023/11/10 14:09:23 by mhiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  ./src/so_long.c ./src/map_checker.c ./src/controls.c ./src/img.c

OBJS = $(SRC:.c=.o)
GNL_OBJS = $(GNL:.c=.o)
ALL_OBJS = $(OBJS) $(GNL_OBJS)

C = gcc

FLAGS = -Wall -Wextra -Werror

MLX_PATH = mlx/
MLX = -L $(MLX_PATH) $(MLX_PATH)libmlx.a -lmlx -framework OpenGL -framework AppKit

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
	@make -C $(MLX_PATH)
	@$(C) $(FLAGS) $(ALL_OBJS) $(MLX) $(LIBFT) -o $(NAME)
	

bonus: $(OBJ) $(BONUS_OBJS)
	@$(C) $(FLAGS) $(SRC)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
fclean: clean
	@$(RM) $(NAME) $(BONUS_OBJS) $(OBJS)
re: fclean all
.PHONY: all fclean clean re 
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:11:58 by mhiguera          #+#    #+#             */
/*   Updated: 2023/11/19 18:29:51 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#   define SO_LONG_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../gnl/get_next_line.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define ARROW_UP		126
# define ARROW_DOWN		125
# define ARROW_LEFT		123
# define ARROW_RIGHT	124

# define DESTROY_NOTIFY	17

typedef struct s_map {
    void    *mlx;
    void    *mlx_win;
    char    **map;
    int     row;
    int     col;
    int     width;
    int     height;
}   t_map;

typedef struct s_game {
	char    *img;
    void    *floor;
    void    *collect;
    void    *exit;
    void    *player_y;
    void    *player_x;
    int    img_height;
    int    img_width;
}   t_game;

void	ft_error(char *str);
void	check_extension(char *argv);
void    read_map(char *argv);
void    check_borders(char **map, int height);
void    check_char(char **map, int height);
void    ft_init();
void    count_items(char **map, int height);
void    init_xpm();
int	    key_hooks(int keycode, t_map *map);
void    print_sprites(char *relative_path, t_map *map);
void    print_floor_walls(t_map *map, char **mapi);
void    check_different(char **map, int height);
void    map_checker(char **map, int height);

#endif
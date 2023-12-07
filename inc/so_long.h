/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:11:58 by mhiguera          #+#    #+#             */
/*   Updated: 2023/12/07 19:11:27 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include <mlx.h>
# include "../libft/libft.h"

# define KEY_ESC		53
# define A 0
# define S 1
# define D 2
# define W 13

# define DESTROY_NOTIFY	17

typedef struct s_game {
    void    *img;
    void    *floor;
    int all_coins;
    int exit_count;
    int player_count;
    int player_y;
    int player_x;
    int coins;
    int img_height;
    int img_width;
    int movements;   
    int exit_row;
    int exit_col;
    char    **exit_position;
}   t_game;

typedef struct s_map {
    void    *mlx;
    void    *mlx_win;
    char    **map;
    int row;
    int col;
    int width;
    int height;
    char    **map_copy;
    int coins_copy;
    t_game  game;
}   t_map;


void    ft_error(char *str);
void    check_extension(char *argv);
void    read_map(char *argv);
void    check_borders(t_map *map, int height);
void    check_char(t_map *map, int height);
void    ft_init(t_map *map, int height);
void    count_items(t_map *map, int height);
int key_hooks(int keycode, t_map *map);
void    print_sprites(char *relative_path, t_map *map, int x, int y);
void    print_floor_walls(t_map *map);
void    check_different(t_map *map, int height);
void    map_checker(t_map *map, int height);
int you_win(t_game *game);
void    flood_fill_from_exit(t_map *map, int row, int col);
void    flood_fill_from_player(t_map *map, int row, int col);
void    check_path(t_map *map);

#endif
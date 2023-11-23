/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:32:47 by mhiguera          #+#    #+#             */
/*   Updated: 2023/11/23 19:14:31 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//FALTA POR ARREGLAR LO DEL PRINTF QUE ESTÁ MAL PUESTAN LAS POSICIONES, PORQUE NO FUNCIONA EL DOBLE COMPROBADOR PARA LA SALIDA
void go_up(t_map *map, t_game *game)
{
	printf("%c\n", (map->map[game->player_y][game->player_x]));
	if ((map->map[(game->player_y - 1)][game->player_x]) == 'C')
		{
			game->coins--;
			if (game->coins == 0 && 
			(map->map[(game->player_y - 1)][game->player_x]) == 'E')
			{
					you_win(game);
			}
		}
	map->map[(game->player_y - 1)][game->player_x] = 'P';
	map->map[game->player_y][game->player_x] = '0';
	game->player_y--;
	game->movements++;
	print_floor_walls(map);
	
}

void go_down(t_map *map, t_game *game)
{
	printf("%c\n", (map->map[game->player_y][(game->player_x + 1)]));
	if (map->map[(game->player_y + 1)][game->player_x] == 'C')
		{
			game->coins--;
			if (game->coins == 0 && 
			(map->map[(game->player_y + 1)][game->player_x]) == 'E')
					you_win(game);
		}
	map->map[(game->player_y + 1)][game->player_x] = 'P';
	map->map[game->player_y][game->player_x] = '0';
	game->player_y++;
	game->movements++;
	print_floor_walls(map);
}

void go_left(t_map *map, t_game *game)
{
	printf("%c\n", (map->map[game->player_y][(game->player_x + 1)]));
	if ((map->map[game->player_y][(game->player_x - 1)]) == 'C')
		{
			game->coins--;
			if (game->coins == 0 && 
			(map->map[game->player_y][(game->player_x - 1)]) == 'E')
					you_win(game);
		}
	map->map[game->player_y][(game->player_x - 1)] = 'P';
	map->map[game->player_y][game->player_x] = '0';
	game->player_x--;
	game->movements++;
	print_floor_walls(map);
}

void go_right(t_map *map, t_game *game)
{
	printf("%c\n", (map->map[game->player_y][(game->player_x + 1)]));
	if ((map->map[game->player_y][(game->player_x + 1)]) == 'C')
		{
			game->coins--;
			if (game->coins == 0 && 
			(map->map[game->player_y][(game->player_x + 1)]) == 'E')
					you_win(game);
		}
	map->map[game->player_y][(game->player_x + 1)] = 'P';
	map->map[game->player_y][game->player_x] = '0';
	game->player_x++;
	game->movements++;
	print_floor_walls(map);
}

int	key_hooks(int keycode, t_map *map)
{
	t_game *game = &map->game;
	
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->mlx_win);
		exit(0);
	}
	if (keycode == W && (map->map[(game->player_y - 1)][game->player_x]) != '1') 
	{
		go_up(map, game);
	}
	if (keycode == A && (map->map[game->player_y][(game->player_x - 1)]) != '1')
	{
		go_left(map, game);
	}
	if (keycode == S && (map->map[(game->player_y + 1)][game->player_x]) != '1')
	{
		go_down(map, game);
	}
	if (keycode == D && (map->map[game->player_y][(game->player_x + 1)]) != '1')
	{
		go_right(map, game);
	}
	return (0);
}

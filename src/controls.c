/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:32:47 by mhiguera          #+#    #+#             */
/*   Updated: 2023/12/09 12:34:55 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../libft/ft_printf.h"

void	go_up(t_map *map, t_game *game)
{
	if ((map->map[(game->player_y - 1)][game->player_x]) == 'C')
		game->coins--;
	if (game->coins == 0)
		if ((map->map[(game->player_y - 1)][game->player_x] == 'E')
			|| ((game->exit_col == game->player_x)
			&& (game->exit_row == game->player_y - 1)))
			you_win(game);
	map->map[(game->player_y - 1)][game->player_x] = 'P';
	map->map[game->player_y][game->player_x] = '0';
	game->player_y--;
	game->movements++;
	ft_printf("Steps: %d\n", game->movements);
	print_floor_walls(map);
}

void	go_down(t_map *map, t_game *game)
{
	if (map->map[(game->player_y + 1)][game->player_x] == 'C')
		game->coins--;
	if (game->coins == 0)
		if ((map->map[(game->player_y + 1)][game->player_x] == 'E')
			|| ((game->exit_col == game->player_x)
			&& (game->exit_row == game->player_y + 1)))
			you_win(game);
	map->map[(game->player_y + 1)][game->player_x] = 'P';
	map->map[game->player_y][game->player_x] = '0';
	game->player_y++;
	game->movements++;
	ft_printf("Steps: %d\n", game->movements);
	print_floor_walls(map);
}

void	go_left(t_map *map, t_game *game)
{
	if ((map->map[game->player_y][(game->player_x - 1)]) == 'C')
		game->coins--;
	if (game->coins == 0)
		if ((map->map[(game->player_y)][game->player_x - 1] == 'E')
			|| ((game->exit_col == game->player_x - 1)
			&& (game->exit_row == game->player_y)))
			you_win(game);
	map->map[game->player_y][(game->player_x - 1)] = 'P';
	map->map[game->player_y][game->player_x] = '0';
	game->player_x--;
	game->movements++;
	ft_printf("Steps: %d\n", game->movements);
	print_floor_walls(map);
}

void	go_right(t_map *map, t_game *game)
{
	if ((map->map[game->player_y][(game->player_x + 1)]) == 'C')
		game->coins--;
	if (game->coins == 0)
		if ((map->map[(game->player_y)][game->player_x + 1] == 'E')
			|| ((game->exit_col == game->player_x + 1)
			&& (game->exit_row == game->player_y)))
			you_win(game);
	map->map[game->player_y][(game->player_x + 1)] = 'P';
	map->map[game->player_y][game->player_x] = '0';
	game->player_x++;
	game->movements++;
	ft_printf("Steps: %d\n", game->movements);
	print_floor_walls(map);
}

int	key_hooks(int keycode, t_map *map)
{
	t_game	*game;

	game = &map->game;
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->mlx_win);
		exit(0);
	}
	if (keycode == W && (map->map[(game->player_y - 1)][game->player_x]) != '1')
		go_up(map, game);
	if (keycode == A && (map->map[game->player_y][(game->player_x - 1)]) != '1')
		go_left(map, game);
	if (keycode == S && (map->map[(game->player_y + 1)][game->player_x]) != '1')
		go_down(map, game);
	if (keycode == D && (map->map[game->player_y][(game->player_x + 1)]) != '1')
		go_right(map, game);
	return (0);
}

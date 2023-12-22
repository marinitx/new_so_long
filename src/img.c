/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:39:25 by mhiguera          #+#    #+#             */
/*   Updated: 2023/12/22 20:12:15 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_sprites(char *relative_path, t_map *map, int col, int row)
{
	t_game	*game;

	game = &map->game;
	game->img = mlx_xpm_file_to_image(map->mlx,
			relative_path, &game->img_width, &game->img_height);
	if (!game->img)
		ft_error("Error\nFailed to load XPM files\n");
	mlx_put_image_to_window(map->mlx, map->mlx_win, game->img,
		col * 50, row * 50);
}

void	print_walls(t_map *map)
{
	int		col;
	int		row;
	char	*relative_path;

	row = 0;
	col = 0;
	relative_path = "./xpm/waterlily.xpm";
	while (row < map->height)
	{
		col = 0;
		while (map->map[row][col] != '\n' && map->map[row][col] != '\0')
		{
			if (map->map[row][col] == '1')
				print_sprites(relative_path, map, col, row);
			col++;
		}
		row++;
	}
}

void	print_else(t_map *map, t_game *game)
{
	int		col;
	int		row;
	char	*relative_path;

	row = 0;
	col = 0;
	relative_path = "./xpm/frog.xpm";
	while (map->map[row][col] != '\0')
	{
		col = 0;
		while (map->map[row][col] != '\n')
		{
			if (map->map[row][col] == 'P')
				print_sprites("./xpm/frog.xpm", map, col, row);
			if (map->map[row][col] == 'C')
				print_sprites("./xpm/fly.xpm", map, col, row);
			if (game->coins == 0)
				print_sprites("./xpm/rock.xpm", map,
					game->exit_col, game->exit_row);
			col++;
		}
		row++;
	}
}

//On start, print all the floor tiles.
void	print_floor_walls(t_map *map)
{
	t_game	*game;
	char	*relative_path;
	int		row;
	int		col;

	row = 0;
	col = 0;
	relative_path = "./xpm/water.xpm";
	game = &map->game;
	while (row < map->height)
	{
		col = 0;
		while (map->map[row][col] != '\n' && map->map[row][col] != '\0')
		{
			print_sprites(relative_path, map, col, row);
			col++;
		}
		row++;
		print_walls(map);
		print_else(map, game);
	}
}

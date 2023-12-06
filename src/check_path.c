/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:21:37 by mhiguera          #+#    #+#             */
/*   Updated: 2023/12/06 18:36:21 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../libft/ft_printf.h"

void	check_path(t_map *map)
{
	printf("Este es el valor de coins_copy: %d y el de coins_copy2: %d\n", map->coins_copy, map->coins_copy2);
	if (map->coins_copy > 0 || map->coins_copy2 > 0)
		ft_error("There is no valid path!");
}

void	flood_fill_from_player(t_map *map, int row, int col)
{	
	t_game *game = &map->game;

	map->map_copy = map->map;
	
	printf("Este es el valor de player_y: %d y el de player_x: %d\n", game->player_y, game->player_x);
	printf("row: %d col: %d\n", row, col);
	printf("Esto es map_copy: %c\n", map->map_copy[row][col]);
	if (map->map_copy[row][col] != '1')
	{	
		printf("Este es el valor de las coins: %d\n", map->coins_copy);
		if (map->map_copy[row][col] == 'C')
			map->coins_copy--;
		map->map_copy[row][col] = '1';
		if (map->map_copy[row][col + 1] != '1'
			&& map->map_copy[row][col + 1] != 'E')
			flood_fill_from_player(map, row, col + 1);
		if (map->map_copy[row][col - 1] != '1'
			&& map->map_copy[row][col - 1] != 'E')
			flood_fill_from_player(map, row, col - 1);
		if (map->map_copy[row + 1][col] != '1'
			&& map->map_copy[row + 1][col] != 'E')
			flood_fill_from_player(map, row + 1, col);
		if (map->map_copy[row - 1][col] != '1'
			&& map->map_copy[row - 1][col] != 'E')
			flood_fill_from_player(map, row - 1, col);
	}
}

void	flood_fill_from_exit(t_map *map, int row, int col)
{
	t_game *game = &map->game;
	
	//printf("Este es el valor de exit_row: %d y el de exit_col: %d\n", game->exit_row, game->exit_col);
	if (map->map_copy2[row][col] != '1')
	{
		if (map->map_copy2[row][col] == 'C')
			map->coins_copy2--;
		map->map_copy2[row][col] = '1';
		if (map->map_copy2[row][col + 1] != '1')
			flood_fill_from_exit(map, row, col + 1);
		if (map->map_copy2[row][col - 1] != '1')
			flood_fill_from_exit(map, row, col - 1);
		if (map->map_copy2[row + 1][col] != '1')
			flood_fill_from_exit(map, row + 1, col);
		if (map->map_copy2[row - 1][col] != '1')
			flood_fill_from_exit(map, row - 1, col);
	}	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:21:37 by mhiguera          #+#    #+#             */
/*   Updated: 2023/12/07 18:13:39 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../libft/ft_printf.h"

void	check_path(t_map *map)
{
	t_game *game = &map->game;
	
	if (map->coins_copy > 0 || game->exit_count > 0)
		ft_error("There is no valid path!");
}

void	flood_fill_from_player(t_map *map, int row, int col)
{	
	t_game *game = &map->game;

	if (map->map_copy[row][col] != '1')
	{	
		printf("Este es el valor de las coins: %d\n", map->coins_copy);
		if (map->map_copy[row][col] == 'C')
			map->coins_copy--;
		if (map->map_copy[row][col] == 'E')
			game->exit_count--;
		map->map_copy[row][col] = '1';
		if (map->map_copy[row][col + 1] != '1')
			flood_fill_from_player(map, row, col + 1);
		if (map->map_copy[row][col - 1] != '1')
			flood_fill_from_player(map, row, col - 1);
		if (map->map_copy[row + 1][col] != '1')
			flood_fill_from_player(map, row + 1, col);
		if (map->map_copy[row - 1][col] != '1')
			flood_fill_from_player(map, row - 1, col);
	}
}
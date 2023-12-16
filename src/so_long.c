/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:11:27 by mhiguera          #+#    #+#             */
/*   Updated: 2023/12/16 12:38:43 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	game_over(void)
{
	exit(0);
	return (0);
}

void	ft_init(t_map *map, int height)
{
	int	row;
	int	width;

	row = 0;
	width = (ft_strlen(map->map[row]) - 1);
	map->height = height;
	map->mlx = mlx_init();
	if (!(map->mlx))
		ft_error("Error\nFailed to load MLX\n");
	map->mlx_win = mlx_new_window(map->mlx, 50 * width, 50 * height, "so_long");
	if (!(map->mlx_win))
		ft_error("Error\nFailed to load window\n");
	print_floor_walls(map);
	mlx_hook(map->mlx_win, 02, 0, key_hooks, map);
	mlx_hook(map->mlx_win, 17, 1L << 0, game_over, map);
	mlx_loop(map->mlx);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		check_extension(argv[1]);
	else
		ft_error("Error\nInvalid number of arguments\n");
	return (0);
}

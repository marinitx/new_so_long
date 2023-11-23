/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:11:27 by mhiguera          #+#    #+#             */
/*   Updated: 2023/11/23 16:54:53 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	game_over(int keycode, t_map *map)
{
	(void)keycode;
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit(0);
	return (0);
}

void init_xpm(char **map, int height)
{
  
}


void ft_init(t_map *map, int height)
{
	t_game	game;
	int row;
	int width;
	char	*relative_path = "./xpm/frog.xpm";
	// int		img_width;
	// int		img_height;

	row = 0;
	game.movements = 0; //no se si esto va aqui pero bueno es donde inicializo los movimientos
	width = (ft_strlen(map->map[row]) - 1);
	map->mlx = mlx_init();
	if (!(map->mlx))
		ft_error("Failed to load MLX");
	map->mlx_win = mlx_new_window(map->mlx, 50 * width, 50 * height, "so_long");
	if (!(map->mlx_win))
		ft_error("Failed to load window");
	print_floor_walls(map);
	//game.img = mlx_xpm_file_to_image(map.mlx, "/Users/mhiguera/Desktop/so_long/xpm/frog.xpm", &game.img_width, &game.img_height);
	//if (!game.img)
	//	ft_error("Failed to read XPM files");
	//mlx_put_image_to_window(map.mlx, map.mlx_win, game.img, 0, 0);
	printf("\n%s\n", "hola");
	mlx_hook(map->mlx_win, 02, 0, key_hooks, map);
	mlx_hook(map->mlx_win, 17, 1L << 0, game_over, map);
	mlx_loop(map->mlx);
}


int main (int argc, char *argv[])
{
	t_map	map;
	t_game game;
	
	if (argc == 2)
		check_extension(argv[1]);

    else
		ft_error("\nInvalid number of arguments");
 
    return (0);
}

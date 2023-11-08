/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:11:27 by mhiguera          #+#    #+#             */
/*   Updated: 2023/11/08 17:41:25 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void init_xpm()
{
    void	*mlx;
	void	*img;
	char	*relative_path = "./xpm/frog.xpm";
	int		img_width;
	int		img_height;
    
    mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
}

int	game_over(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->mlx_win);
		exit(0);
	}
		
	return (0);
}

void ft_init()
{
	t_map	map;
	void	*img;
	char	*relative_path = "./xpm/frog.xpm";
	int		img_width;
	int		img_height;
	
	map.mlx = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx, 1080, 1080, "so_long");
	img = mlx_new_image(map.mlx, 50, 50);
	img = mlx_xpm_file_to_image(map.mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(map.mlx, map.mlx_win, img, 5, 5);
	printf("\n%s\n", "hola");
	mlx_hook(map.mlx_win, 02, 0, game_over, &map);
	mlx_hook(map.mlx_win, 2, 1L << 0, game_over, &map);
	mlx_loop(map.mlx);
}

int main (int argc, char *argv[])
{
	t_map	map;
	
	if (argc == 2)
	{		
		check_extension(argv[1]);
		//printf("%s\n", "hola");
		//printf("%s\n", "holaaaaaaaa");
		ft_init();
		//map.mlx = mlx_init();
		//map.mlx_win = mlx_new_window(map.mlx, 1080, 1080, "so_long");
		//mlx_loop(map.mlx);
	}

    else
		ft_error("\nInvalid number of arguments");
 
    return (0);
}

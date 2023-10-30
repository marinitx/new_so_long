/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:11:27 by mhiguera          #+#    #+#             */
/*   Updated: 2023/10/30 18:55:30 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void ft_init()
{
	t_map	map;
	
	map.mlx = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx, 1080, 1080, "so_long");
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

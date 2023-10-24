/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:11:27 by mhiguera          #+#    #+#             */
/*   Updated: 2023/10/23 18:50:27 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main (int argc, char *argv[])
{
	t_map	map;
	
	if (argc == 2)
	{		
		check_extension(argv[1]);
		map.mlx = mlx_init();
		map.mlx_win = mlx_new_window(map.mlx, 1080, 1080, "so_long");
		mlx_loop(map.mlx);
	}

    else
		ft_error("\nInvalid number of arguments");
 
    return (0);
}

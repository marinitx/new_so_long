/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:11:27 by mhiguera          #+#    #+#             */
/*   Updated: 2023/10/15 14:42:49 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long.h"

int	main()
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	t_map	map;

	mlx = mlx_init();
	mlx_win = mlx_new_window(map.mlx, 1080, 1080, "so_long");
	img = mlx_xpm_file_to_image(map.mlx, "../xpm/frog.xpm", 
		&map.img_width, &map.img_height);
	mlx_put_image_to_window(map.mlx, map.win, img, 0, 0);
	mlx_loop(mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:32:47 by mhiguera          #+#    #+#             */
/*   Updated: 2023/11/14 18:54:58 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_hooks(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->mlx_win);
		exit(EXIT_SUCCESS);
	}
	/*
	if (keycode == KEY_W || keycode == ARROW_UP)
		w_press(map);
	if (keycode == KEY_A || keycode == ARROW_LEFT)
		a_press(map);
	if (keycode == KEY_S || keycode == ARROW_DOWN)
		s_press(map);
	if (keycode == KEY_D || keycode == ARROW_RIGHT)
		d_press(map);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->map.footprints, 10, 10);
	*/
	return (0);
}
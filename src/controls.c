/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:32:47 by mhiguera          #+#    #+#             */
/*   Updated: 2023/11/23 12:27:27 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void go_up(t_map map)
{
	t_game game;
	
	if ((game.player_y - 1) == 'C')
		{
			if (game.coins == 0)
					you_win(game);
			game.coins--;
		}
	printf("%s\n", "yooo por ahí no paso");
	map.map[(game.player_y - 1)][game.player_x] = 'P';
	map.map[game.player_y][game.player_x] = '0';
	game.player_y--;
	game.movements++;
}

void go_down(t_map map, char **mapi)
{
	t_game game;
	
	if ((game.player_y + 1) == 'C')
		{
			if (game.coins == 0)
					you_win(game);
			game.coins--;
		}
	mapi[game.player_y][game.player_x] = '0';
	mapi[(game.player_y + 1)][game.player_x] = 'P';
	game.player_y++;
	game.movements++;
}

void go_left(t_map map, char **mapi)
{
	t_game game;
	
	if ((game.player_x - 1) == 'C')
		{
			if (game.coins == 0)
				you_win(game);
			game.coins--;
		}
	mapi[game.player_y][game.player_x] = '0';
	mapi[game.player_y][(game.player_x - 1)] = 'P';
	game.player_x--;;
	game.movements++;
}

void go_right(t_map map, char **mapi)
{
	t_game game;
	
	if ((game.player_x + 1) == 'C')
		{
			if (game.coins == 0)
					you_win(game);
			game.coins--;
		}
	mapi[game.player_y][game.player_x] = '0';
	mapi[game.player_y][(game.player_x + 1)] = 'P';
	game.player_x++;
	game.movements++;
}

int	key_hooks(int keycode, t_map map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map.mlx, map.mlx_win);
		exit(0);
	}
	if (keycode == W) //y la posición de encima es distinta a 1
	{
		printf("hoooola caracola\n");
		go_up(map);
	}
	return (0);
}
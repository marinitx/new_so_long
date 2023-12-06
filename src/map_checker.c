/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:53:03 by mhiguera          #+#    #+#             */
/*   Updated: 2023/12/06 18:41:15 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdio.h>

void check_different(t_map *map, int height)
{
    int row;
    int col;

    row = 0;
    col = 0;
    while (map->map[row][col] != '\0' && row < height)
    {
        col = 0;
        while (map->map[row][col] != '\n')
        {
            if ((map->map[row][col] != '0' && map->map[row][col] != '1' && map->map[row][col] != 'C') &&
            (map->map[row][col] != 'E' && map->map[row][col] != 'P' && map->map[row][col] != '\n' && map->map[row][col] != '\0'))
                 ft_error("Wrong characters on the map!");
            col++;
        }
        row++;
    }
}
//DIVIDIR EN 2
void check_char(t_map *map, int height)
{
    t_game  game;
    int row;
    int col;

    row = 0;
    game.all_coins = 0; 
    game.exit_count = 0;
    game.player_count = 0;
    game.movements = 0;
    col = 0;
    
    while (map->map[row][col] != '\0' && row < height)
    {
        col = 0;
        while (map->map[row][col] != '\n')
        {
            if (map->map[row][col] == 'E')
            {
                game.exit_count++;
                game.exit_row = row;
                game.exit_col = col;
            }
            if (map->map[row][col] == 'P')
            {
                game.player_y = row;
                game.player_x = col;
                game.player_count++;
            }
            if (map->map[row][col] == 'C')
                game.all_coins++;
            col++;
        }
            row++;
    }
    game.coins = game.all_coins;
    map->coins_copy = game.all_coins;
    map->coins_copy2 = game.all_coins;
    if (game.exit_count != 1)
        ft_error("Map not valid");
    if (game.player_count != 1)
        ft_error("Map not valid");
    map->game = game;
}
//DIVIDIR EN 2
void check_borders(t_map *map, int height)
{
    int row;
    int col;
    int width;
    
    row = 0;
    col = 0;
    width = (ft_strlen(map->map[row]) - 1);
    while (map->map[row][col] != '\0')
    {
        col = 0;
        if ((row == 0 || row == height - 1))
        {
            while (map->map[row][col] != '\n' && map->map[row][col] != '\0')
            {
                if (map->map[0][col] != '1' || map->map[height - 1][col] != '1')
                    ft_error("The map is not surrounded by walls!");
                col++;
            }
        }
        if (row == height - 1)
        {
            while (map->map[row][col] != '\0')
            {
                if (map->map[0][col] != '1' || map->map[height - 1][col] != '1')
                    ft_error("The map is not surrounded by walls!");
                col++;
            }
        }
        if ((row > 0) && (row < height - 1))
        {
            if (map->map[row][0] != '1' || map->map[row][width - 1] != '1')
                ft_error("The map is not surrounded by walls!");
            col++;
        }
        if (row < height - 1)
            row++;
    }
}

void check_width(t_map *map, int height)
{
    int row;
    int col;
    int width;

    row = 0;
    col = 0;
    width = (ft_strlen(map->map[row] - 1));
    while (map->map[row])
    {
        //printf("esto va valiendo width: %d y esto debería valer %d\n", ft_strlen(map->map[row] - 1), width);
        if (ft_strlen(map->map[row] - 1) != width && row < height - 1)
            ft_error("The map is not rectangular!");
        if (row == height - 1 && ft_strlen(map->map[row] - 1) != (width - 1))
            ft_error("The map is not rectangular!");
        row++;
    }
}

void map_checker(t_map *map, int height)
{   
    t_game *game = &map->game;
    
    check_width(map, height);
    check_borders(map, height);
    check_char(map, height);
    check_different(map, height);
    //********AQUI ESTÁ EL FALLO. RESULTA QUE MAP NO LO COPIA COMO TAL PORQUE TAMBIÉN LO VA CAMBIANDO!! POR ESO AL CAMBIAR MAP Y PASARSELO A LA OTRA FUNCIÓN YA NO FUNCIONA***///
    //map->map_copy = map->map;
    //flood_fill_from_player(map, game->player_y, game->player_x);
    //map->map_copy2 = map->map;
    //flood_fill_from_exit(map, game->exit_row, game->exit_col);
    //check_path(map);
    ft_init(map, height);
}
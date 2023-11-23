/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:53:03 by mhiguera          #+#    #+#             */
/*   Updated: 2023/11/21 18:45:53 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdio.h>

void	ft_error(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
    exit(1);
}

void check_different(char **map, int height)
{
    int row;
    int col;

    row = 0;
    col = 0;
    while (map[row][col] != '\0' && row < height)
    {
        col = 0;
        while (map[row][col] != '\n')
        {
            if ((map[row][col] != '0' && map[row][col] != '1' && map[row][col] != 'C') &&
            (map[row][col] != 'E' && map[row][col] != 'P' && map[row][col] != '\n' && map[row][col] != '\0'))
                 ft_error("Wrong characters on the map!");
            col++;
        }
        row++;
    }
}

void check_char(char **mapi, int height) //dividir esta función en dos
{
    //printf("\nentro al check char\n");
    t_game  game;
    t_map map;
    int row;
    int col;

    row = 0;
    game.all_coins = 0; 
    game.exit_count = 0;
    game.player_count = 0;
    col = 0;
    //printf("Estoy en la fila %d y en la columna %d\n", row, col);
    
    while (mapi[row][col] != '\0' && row < height)
    {
        col = 0;
        //printf("Estoy en la fila %d y en la columna %d\n", row, col);
        while (mapi[row][col] != '\n')
        {
            printf("\n%c\n", mapi[row][col]);
            if (mapi[row][col] == 'E')
                game.exit_count++;
            if (mapi[row][col] == 'P')
            {
                game.player_y = row;
                game.player_x = col;
                game.player_count++;
            }
            if (mapi[row][col] == 'C')
                game.all_coins++;
            col++;
            printf("Estoy en la fila %d y en la columna %d\n", row, col);
        }
        //if (row < height - 1)
            row++;
    }
    game.coins = game.all_coins;
    printf("\n%s\n", "aqui me habré leido todo el mapa en los caracteres");
    printf("Este es el game player count: %d\n", game.player_count);
    printf("Esta es la posición de player x: %d\n Esta es la posición de player y: %d\n", game.player_x, game.player_y);
    if (game.exit_count != 1)
        ft_error("Map not valid");
    if (game.player_count != 1)
        ft_error("Map not valid");
    
}

//Checks if every border is closed by walls (1)
void check_borders(char **map, int height)
{
    int row;
    int col;
    int width;
    
    row = 0;
    col = 0;
    //printf("aksjdjfhkjasdf %s\n", map->map[0]);
    width = (ft_strlen(map[row]) - 1); //esto me da segmentation porque no logra coger el string
    //printf("llego al check char\n");

    //printf("llego al check char\n");
    //printf("\n%s\n", "esto es un printf de comprobación");
    while (map[row][col] != '\0')
    {
        col = 0;
        if (row == 0 || row == height - 1)
        {
            while (map[row][col] != '\n' && map[row][col] != '\0')
            {
                if (map[0][col] != '1' || map[height - 1][col] != '1')
                    ft_error("The map is not surrounded by walls!");
                col++;
            }
        }
        if ((row > 0) && (row < height - 1))
        {
            if (map[row][0] != '1' || map[row][width - 1] != '1')
                ft_error("The map is not surrounded by walls!");
            col++;
        }
        if (row < height - 1)
            row++;
    }
}

void map_checker(char **map, int height)
{
    //t_map *map;
    
    check_borders(map, height);
    check_char(map, height);
    check_different(map, height);
    ft_init(map, height);
}
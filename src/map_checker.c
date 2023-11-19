/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:53:03 by mhiguera          #+#    #+#             */
/*   Updated: 2023/11/19 19:20:46 by mhiguera         ###   ########.fr       */
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
    exit(EXIT_FAILURE);
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

void check_char(char **map, int height) //dividir esta función en dos
{
    //printf("\nentro al check char\n");
    int collectables;
    int exit;
    int num_exit;
    int player;
    int row;
    int col;

    row = 0;
    num_exit = 0;
    collectables = 0;
    exit = 0;
    player = 0;
    col = 0;
    //printf("Estoy en la fila %d y en la columna %d\n", row, col);
    
    while (map[row][col] != '\0' && row < height)
    {
        col = 0;
        //printf("Estoy en la fila %d y en la columna %d\n", row, col);
        while (map[row][col] != '\n')
        {
            printf("\n%c\n", map[row][col]);
            if (map[row][col] == 'E')
                num_exit++;
            if (map[row][col] == 'P')
                player++;
            if (map[row][col] == 'C')
                collectables++;
            col++;
            printf("Estoy en la fila %d y en la columna %d\n", row, col);
        }
        //if (row < height - 1)
            row++;
    }
    printf("\n%s\n", "aqui me habré leido todo el mapa en los caracteres");
    if (num_exit != 1)
        ft_error("Map not valid");
    if (player != 1)
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
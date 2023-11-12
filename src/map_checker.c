/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:53:03 by mhiguera          #+#    #+#             */
/*   Updated: 2023/11/12 21:21:09 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdio.h>

void check_char(t_map *map, int height)
{
    //printf("\nentro al check char\n");
    int collectables;
    int exit;
    int num_exit;
    int player;
    int row;
    int col;

    map->row = 0;
    num_exit = 0;
    collectables = 0;
    exit = 0;
    player = 0;
    map->col = 0;
    //printf("Estoy en la fila %d y en la columna %d\n", row, col);
    
    while (map->map[row][col] != '\0' && map->row < height)
    {
        map->col = 0;
        //printf("Estoy en la fila %d y en la columna %d\n", row, col);
        while (map->map[row][col] != '\n')
        {
            printf("\n%c\n", map->map[row][col]);
           if ((map->map[row][col] != '0' && map->map[row][col] != '1' && map->map[row][col] != 'C') &&
           (map->map[row][col] != 'E' && map->map[row][col] != 'P' && map->map[row][col] != '\n' && map->map[row][col] != '\0'))
                ft_error("Wrong characters on the map!");
            if (map->map[row][col] == 'E')
                num_exit++;
            if (map->map[row][col] == 'P')
                player++;
            if (map->map[row][col] == 'C')
                collectables++;
            map->col++;
            printf("Estoy en la fila %d y en la columna %d\n", row, col);
        }
        //if (row < height - 1)
            map->row++;
    }
    printf("\n%s\n", "aqui me habré leido todo el mapa en los caracteres");
    if (num_exit != 1)
        ft_error("Map not valid");
    if (player != 1)
        ft_error("Map not valid");
    
}

//Checks if every border is closed by walls (1)
void check_borders(t_map *map, int height)
{
    int width;
    int row;
    int col;

    map->row = 0;
    map->col = 0;
    width = (ft_strlen(map->map[row]) - 1); //esto me da segmentation porque no logra coger el string

    //printf("llego al check char\n");
    printf("\n%s\n", "esto es un printf de comprobación");
    check_char(map, height);
    while (map->map[row][col] != '\0')
    {
        map->col = 0;
        if (map->row == 0 || map->row == height - 1)
        {
            while (map->map[row][col] != '\n' && map->map[row][col] != '\0')
            {
                if (map->map[0][col] != '1' || map->map[height - 1][col] != '1')
                    ft_error("The map is not surrounded by walls!");
                map->col++;
            }
        }
        if ((map->row > 0) && (map->row < height - 1))
        {
            if (map->map[row][0] != '1' || map->map[row][width - 1] != '1')
                ft_error("The map is not surrounded by walls!");
            map->col++;
        }
        if (map->row < height - 1)
            map->row++;
    }
    ft_init(map);
}

//Creates with malloc a 2d char map as found in file
void read_map(char *argv, t_map *map)
{
    int fd;
    char *tmp;
    int height;
    int row;
    int col;

    tmp = "holi";
    height = -1;
    map->row = 0;
    fd = open(argv, O_RDONLY);
    while (tmp)
    {
        height++;
        tmp = get_next_line(fd);
        free(tmp);
    }
    map->map = malloc(sizeof(char *) * (height + 1));
    if (!map->map)
        ft_error("\nFile not found!");
    close(fd);
    fd = open(argv, O_RDONLY);
    if (fd == - 1)
        ft_error("Could not read the file!");
    while (map->row < height)
    {
        map->map[row] = get_next_line(fd);
        printf("%s", map->map[row]); //borrar el salto de linea
        map->row++;
    }
    check_borders(map, height);
    close(fd);
}

void	check_extension(char *argv, t_map *map)
{
	int		start;
	char	*extension;

	start = ft_strlen(argv) - 4;
	extension = ft_substr(argv, start, 4);
	if (ft_strncmp(".ber", extension, 4) != 0)
            ft_error("The extension is not .ber!");
    read_map(argv, map);
    printf("\n"); //borrar
}

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

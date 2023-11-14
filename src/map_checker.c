/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:53:03 by mhiguera          #+#    #+#             */
/*   Updated: 2023/11/14 19:12:53 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdio.h>

void check_char(char **map, int height)
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
           if ((map[row][col] != '0' && map[row][col] != '1' && map[row][col] != 'C') &&
           (map[row][col] != 'E' && map[row][col] != 'P' && map[row][col] != '\n' && map[row][col] != '\0'))
                ft_error("Wrong characters on the map!");
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
    int width;
    int row;
    int col;

    row = 0;
    col = 0;
    printf("aksjdjfhkjasdf %s\n", map[0]);
    width = (ft_strlen(map[row]) - 1); //esto me da segmentation porque no logra coger el string
    printf("llego al check char\n");

    //printf("llego al check char\n");
    printf("\n%s\n", "esto es un printf de comprobación");
    check_char(map, height);
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
    ft_init(map);
}

//Creates with malloc a 2d char map as found in file
void read_map(char *argv)
{
    int fd;
    char *tmp;
    int height;
    int row;
    int col;
    char **map;

    tmp = "holi";
    height = -1;
    row = 0;
    fd = open(argv, O_RDONLY);
    while (tmp)
    {
        height++;
        tmp = get_next_line(fd);
        free(tmp);
    }
    map = malloc(sizeof(char *) * (height + 1));
    if (!map)
        ft_error("\nFile not found!");
    close(fd);
    fd = open(argv, O_RDONLY);
    if (fd == - 1)
        ft_error("Could not read the file!");
    while (row < height)
    {
        map[row] = get_next_line(fd);
        printf("%s", map[row]); //borrar el salto de linea
        row++;
    }
    check_borders(map, height);
    close(fd);
}

void	check_extension(char *argv)
{
	int		start;
	char	*extension;

	start = ft_strlen(argv) - 4;
	extension = ft_substr(argv, start, 4);
    printf("%s\n", extension);
	if (ft_strncmp(".ber", extension, 4) != 0)
            ft_error("The extension is not .ber!");
    read_map(argv);
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

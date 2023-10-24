/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:53:03 by mhiguera          #+#    #+#             */
/*   Updated: 2023/10/24 15:49:48 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdio.h>

//Checks if every border is closed by walls (1)
void check_borders(char **map, int height)
{
    int row;
    int col;
    int width;

    row = 0;
    col = 0;
    width = (ft_strlen(map[row]) - 1);
    while (map[row][col] != '\0')
    {
        if (row == 0 || row == height - 1) //primera y ultima row
        {
            while (map[row][col] != '\n' && map[row][col] != '\0')
            {
                if (map[0][col] != '1' || map[height - 1][col] != '1')
                    ft_error("The map is not surrounded by walls!");
                col++;
            }
        }
        if ((row > 0) && (row < height - 1)) //rows entre medias
        {
            printf("Último caracter del mapa de la fila %d es %c\n", row, map[row][width - 1]);
            if (map[row][0] != '1' || map[row][width - 1] != '1')
                ft_error("The map is not surrounded by walls!");
            col++;
        }
        // Porfi, no sumes más, basta vale?
        printf("\nEstoy en la fila: %d\n", row);
        row++;
        printf("Estoy en la columna: %d\n", col);
        col = 0;
        printf("caracter para el while: %c\n", map[row][col]);
    }
}

//Creates with malloc a 2d char map as found in file
void read_map(char *argv)
{
    int fd;
    char *tmp;
    int row;
    char **map;
    int height;

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
        printf("%s", map[row]);
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
	if (ft_strncmp(".ber", extension, 4) != 0)
            ft_error("The extension is not .ber!");
    read_map(argv);
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

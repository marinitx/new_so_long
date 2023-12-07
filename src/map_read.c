/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:53:07 by mhiguera          #+#    #+#             */
/*   Updated: 2023/12/07 17:55:39 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdio.h>

//Creates with malloc a 2d char map as found in file
void read_map(char *argv)
{
    t_map map;
    int fd;
    char *tmp;
    int height;
    int row;

    tmp = "holi";
    height = -1;
    row = 0;
    fd = open(argv, O_RDONLY);
    if (fd <= 0)
		ft_error("Failed to open file");
    while (tmp)
    {
        height++;
        tmp = get_next_line(fd);
        free(tmp);
    }
    map.map = ft_calloc(sizeof(char *), (height + 1));
    map.map_copy = ft_calloc(sizeof(char *), (height + 1));
    if (!map.map)
        ft_error("\nFile not found!");
    close(fd);
    fd = open(argv, O_RDONLY);
    if (fd == - 1)
        ft_error("Could not read the file!");
    while (row < height)
    {
        printf("Esto es lo que va valiendo row: %d y esto es lo que vale height: %d\n", row, height);
        map.map[row] = get_next_line(fd);
        map.map_copy[row] = ft_strdup(map.map[row]);
        printf("%s", map.map[row]); //borrar el salto de linea
        row++;
    }
    printf("\n");
    close(fd);
    map_checker(&map, height);
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
    else
        read_map(argv);
    printf("\n"); //borrar
}

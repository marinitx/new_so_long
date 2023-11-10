/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:39:25 by mhiguera          #+#    #+#             */
/*   Updated: 2023/11/10 14:11:20 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void print_sprites(char *relative_path, t_map *map)
{
    map->img = mlx_xpm_file_to_image(map->mlx, relative_path, map->img_width, map->img_height);
    if (map->img == NULL)
        ft_error("Error en la lectura de imágenes");
    mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, 50, 50);
}

void print_floor_walls(t_map *map, char **map)
{
    //al empezar, pinta todo el mapa de agua
    char *relative_path;
    int row;
    int col;

    row = 0;
    col = 0;
    relative_path = "../xpm/frog.xpm";
    while (map[row][col] != '\0')
    {
        col = 0;
        while (map[row][col] != '\n')
        {
            print_sprites(relative_path, map);
            col++;
        }
        row++;
    }
}
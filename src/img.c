/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:39:25 by mhiguera          #+#    #+#             */
/*   Updated: 2023/11/23 16:51:15 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


void print_sprites(char *relative_path, t_map *map, int x, int y)
{
    t_game *game = &map->game;

    printf("%s\n", relative_path);
    game->img = mlx_xpm_file_to_image(map->mlx, relative_path, &game->img_width, &game->img_height);
    if (!game->img)
        ft_error("Failed to load XPM files");
    mlx_put_image_to_window(map->mlx, map->mlx_win, game->img, x * 50, y * 50);
}

void print_walls(t_map *map)
{
    int col;
    int row;
    int x;
    int y;
    char *relative_path;

    row = 0;
    col = 0;
    x = 0;
    y = 0;
    relative_path = "./xpm/waterlily.xpm";
    while (map->map[row][col] != '\0')
    {
        col = 0;
        x = 0;
        while(map->map[row][col] != '\n')
        {
            if (map->map[row][col] == '1')
                print_sprites(relative_path, map, col, row);
            col++;
            x++;
        }
        row++;
        y++;
    }
}

void print_else(t_map *map)
{
    int col;
    int row;
    int x;
    int y;
    char *relative_path;

    row = 0;
    col = 0;
    x = 0;
    y = 0;
    relative_path = "./xpm/frog.xpm";
    while (map->map[row][col] != '\0')
    {
        col = 0;
        x = 0;
        while(map->map[row][col] != '\n')
        {
            if (map->map[row][col] == 'P')
                print_sprites("./xpm/frog.xpm", map, col, row);
            if (map->map[row][col] == 'C')
                print_sprites("./xpm/fly.xpm", map, col, row);
            if (map->map[row][col] == 'E')
                print_sprites("./xpm/rock.xpm", map, col, row);
            col++;
            x++;
        }
        row++;
        y++;
    }
}

void print_floor_walls(t_map *map)
{
    //al empezar, pinta todo el mapa de agua
    char *relative_path;
    int row;
    int col;
    int x;
    int y;

    row = 0;
    col = 0;
    x = 0;
    y = 0;
    relative_path = "./xpm/water.xpm";
    printf("%s\n", "hasta aquí llega");
    //print_sprites(relative_path, map, mapi);
    printf("Esta es el caracter: %c\n", map->map[row][col]);
    while (map->map[row][col] != '\0')
    {
        printf("Esta es la fila: %i\n", row);
        col = 0;
        x = 0;
        while (map->map[row][col] != '\n')
        {
            print_sprites(relative_path, map, col, row);
            col++;
            x++;
        }
        row++;
        y++;
        printf("Esta es la fila: %i\n", row);
        printf("Este es el caracter: %c\n", map->map[row][col]);
        print_walls(map);
        print_else(map);
    }
}


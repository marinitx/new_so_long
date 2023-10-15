/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:53:03 by mhiguera          #+#    #+#             */
/*   Updated: 2023/10/15 15:35:27 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//Creates with malloc a 2d char map as found in file
void read_map(char *argv, t_map *map)
{
    int filesize;
    int fd;
    char *tmp;
    int row;
   // int col;
   // int j;

    tmp = "holi";
    filesize = -1;
    row = 0;
    fd = open(argv, O_RDONLY);
    while (tmp)
    {
        filesize++;
        tmp = get_next_line(fd);
        free(tmp);
    }
    map = malloc(sizeof(char *) * (filesize + 1));
    if (!map)
        printf("%s", "\nFile not found!");
    close(fd);
    fd = open("map1.ber", O_RDONLY);
    while (row < filesize)
    {
        map[row] = get_next_line(fd);
        printf("%s", map[row]);
        row++;
    }
    close(fd);
    exit(0);
}

int main (int argc, char *argv[])
{
    t_map   map;
    
    if (argc == 2)
        read_map(argv[1], &map);
    return (0);
}
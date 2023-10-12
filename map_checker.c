/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:53:03 by mhiguera          #+#    #+#             */
/*   Updated: 2023/10/12 17:52:20 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "gnl/get_next_line.h"

//Counts the number of lines by '\n'
/*static int count_lines(char *file)
{
    int i;
    int lines;

    i = 0;
    while (file[i] != '\0')
    {
        if ft_strchr(file[i], '\n')
        {
            lines++;
        }
        i++;
    }
    return (lines);
}
*/

 int check_map(char **map, int filesize)
    {
        int row;
        int col;
        int lencol;

        row = 0;
        col = 0;
        lencol = ft_strlen(map[row]);
        while (row < filesize)
        {
            while (map[row][col] != '\n')
            {
                if ((map[1][col] != '\n'))
                {
                    printf("%d", col);
                    //printf("%s", "error en el mapa");
                }
                col++;
            }
            row++;
        }
        printf("\n%d\n", row);
        printf("\n%d\n", col);
        return(0);
    }


//Creates with malloc a 2d char map as found in file
int read_map(char *file)
{
    char **map;
    int filesize;
    int fd;
    char *tmp;
    int row;
    int col;
    int j;

    tmp = "holi";
    filesize = -1;
    fd = open("map1.ber", O_RDONLY);
    while (tmp)
    {
        filesize++;
        tmp = get_next_line(fd);
        free(tmp);
    }
    map = malloc(sizeof(char *) * (filesize + 1));
    if (!map)
        return (0);
    close(fd);
    return (filesize);
}

char save_map(char *file)
{
    int row;
    int col;
    int filesize;
    int j;
    int fd;
    char **map;

    row = 0;
    col = 0;
    j = 0;
    filesize = read_map(file);
    fd = open("map1.ber", O_RDONLY);
    while (row < filesize)
    {
        map[row] = get_next_line(fd);
        printf("%s", map[row]);
        row++;
        
    }
    close(fd);
    printf("%d", filesize);
    check_map(map, filesize);
    exit(0);
}

int main ()
{
    save_map("map1.ber");
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:53:03 by mhiguera          #+#    #+#             */
/*   Updated: 2023/10/15 17:33:10 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//Creates with malloc a 2d char map as found in file
void read_map(char *argv)
{
    int height;
    int fd;
    char *tmp;
    char **map;
    int row;

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
    while (row < height)
    {
        map[row] = get_next_line(fd);
        printf("%s", map[row]);
        row++;
    }
    close(fd);
    exit(0);
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
}
/*
int measure_map(char *argv)
{
    int fd;
    int height;
    char *line;
    
    fd = open(argv, O_RDONLY);
    line = get_next_line(fd);
    map.height = 0;
    map.width = ft_strlen(line) - 1;
    
    while (line)
    {
        line = get_next_line(fd);
        map.line
        
    }
}
*/
int main (int argc, char *argv[])
{   
    if (argc == 2)
        read_map(argv[1]);
    else
        ft_error("\nInvalid number of arguments");
    return (0);
}
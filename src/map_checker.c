/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:53:03 by mhiguera          #+#    #+#             */
/*   Updated: 2023/10/20 11:52:01 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//Checks if every border is closed by walls (1)
void check_borders(char **map, int height)
{
    int row;
    int col;
    int width;

    row = 0;
    col = 0;
    width = 8; //temporary
    while (map)
    {
        if (row == 0 || row == height - 1)
        {
            while (map[row][col] != '\n')
            {
                if (map[row][col] != '1')
                    ft_error("The map is not surrounded by walls!");
                col++;
            }
        }
        if ((row > 0) && (row < height - 1))
        {
            if (map[row][0] != '1' || map[row][width] != '1')
                ft_error("The map is not surrounded by walls!");
        }
        row++;
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
    while (row < height)
    {
        map[row] = get_next_line(fd);
        printf("%s", map[row]);
        row++;
    }
    check_borders(map, height);
    close(fd);
    exit(0);
}

void	check_extension(char *argv)
{
	int		start;
	char	*extension;

	start = ft_strlen(argv) - 4;
	extension = ft_substr(argv, start, 4);
	if (ft_strcmp(".ber", extension) != 0)
		ft_error("The extension is not .ber!");
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
    t_map map;
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
        check_extension(argv[1]);
    else
        ft_error("\nInvalid number of arguments");
    return (0);
}
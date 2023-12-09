/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:53:07 by mhiguera          #+#    #+#             */
/*   Updated: 2023/12/09 13:35:08 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdio.h>

void	check_height(char *argv)
{
	t_map	map;
	int		fd;
	char	*tmp;
	int		height;

	tmp = "holi";
	height = -1;
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
	read_map(argv, &map, height);
}

void	read_map(char *argv, t_map *map, int height)
{
	int	fd;
	int	row;

	row = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Could not read the file!");
	while (row < height)
	{
		map->map[row] = get_next_line(fd);
		map->map_copy[row] = ft_strdup(map->map[row]);
		row++;
	}
	close(fd);
	map_checker(map, height);
}

void	check_extension(char *argv)
{
	int		start;
	char	*extension;

	start = ft_strlen(argv) - 4;
	extension = ft_substr(argv, start, 4);
	if (ft_strncmp(".ber", extension, 4) != 0)
		ft_error("The extension is not .ber!");
	else
		check_height(argv);
}

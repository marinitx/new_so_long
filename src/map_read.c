/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:53:07 by mhiguera          #+#    #+#             */
/*   Updated: 2023/12/22 20:11:50 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdio.h>

void	check_height(char *argv, t_map *map)
{
	int		fd;
	char	*tmp;

	map->height = 0;
	fd = open(argv, O_RDONLY);
	if (fd <= 0)
		ft_error("Error\nFailed to open file\n");
	tmp = get_next_line(fd);
	if (!tmp)
		ft_error("Error\nEmpty map\n");
	while (tmp)
	{
		map->height++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	map->map = ft_calloc(sizeof(char *), (map->height + 1));
	map->map_copy = ft_calloc(sizeof(char *), (map->height + 1));
	if (!map->map || !map->map_copy)
		ft_error("Error\nFile not found!\n");
	close(fd);
	read_map(argv, map);
}

void	read_map(char *argv, t_map *map)
{
	int	fd;
	int	row;

	row = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nCould not read the file!\n");
	while (row < map->height)
	{
		map->map[row] = get_next_line(fd);
		map->map_copy[row] = ft_strdup(map->map[row]);
		row++;
	}
	close(fd);
	map_checker(map);
}

void	check_extension(char *argv, t_map *map)
{
	int		start;
	char	*extension;

	start = ft_strlen(argv) - 4;
	extension = ft_substr(argv, start, 4);
	if (ft_strncmp(".ber", extension, 4) != 0)
		ft_error("Error\nThe extension is not .ber!\n");
	else
		check_height(argv, map);
}

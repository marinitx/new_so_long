/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:57:32 by mhiguera          #+#    #+#             */
/*   Updated: 2023/12/22 20:11:13 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../libft/ft_printf.h"

int	you_win(t_game *game)
{
	int		i;
	char	*str;

	i = 0;
	ft_printf("%s\n", "********************************************");
	str = "You Won. Congrats!\n";
	if (game->coins == 0)
	{
		write(1, str, 19);
		exit(0);
	}
	return (0);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map)
	{
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
}

void	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	exit(1);
}

void	check_borders(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (map->map[row][col] != '\0')
	{
		col = 0;
		if ((row == 0 || row == map->height - 1))
		{
			while (map->map[row][col] != '\n' && map->map[row][col] != '\0')
			{
				if (map->map[0][col] != '1'
					|| map->map[map->height - 1][col] != '1')
					ft_error("Error\nMap is not surrounded by walls!\n");
				col++;
			}
		}
		if (row < map->height - 1)
			row++;
	}
	check_borders2(map, row, col);
}

void	check_width(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	map->width = (ft_strlen(map->map[row]) - 1);
	while (map->map[row])
	{
		if (ft_strlen(map->map[row]) - 1 != map->width && row < map->height - 1)
			ft_error("Error\nThe map is not rectangular!\n");
		if (row == map->height - 1
			&& ft_strlen(map->map[row]) - 1 != (map->width - 1))
			ft_error("Error\nThe map is not rectangular!\n");
		row++;
	}
}

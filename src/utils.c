/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:57:32 by mhiguera          #+#    #+#             */
/*   Updated: 2023/12/09 15:38:40 by mhiguera         ###   ########.fr       */
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
	str = "You Won. Congrats!";
	if (game->coins == 0)
	{
		write(1, str, 18);
		exit(0);
	}
	return (0);
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

void	check_borders(t_map *map, int height)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (map->map[row][col] != '\0')
	{
		col = 0;
		if ((row == 0 || row == height - 1))
		{
			while (map->map[row][col] != '\n' && map->map[row][col] != '\0')
			{
				if (map->map[0][col] != '1' || map->map[height - 1][col] != '1')
					ft_error("Error\nThe map is not surrounded by walls! 1");
				col++;
			}
		}
		if (row < height - 1)
			row++;
	}
	check_borders2(map, height, row, col);
}

void	check_width(t_map *map, int height)
{
	int	row;
	int	col;
	int	width;

	row = 0;
	col = 0;
	width = (ft_strlen(map->map[row] - 1));
	while (map->map[row])
	{
		if (ft_strlen(map->map[row] - 1) != width && row < height - 1)
			ft_error("Error\nThe map is not rectangular! hola hola 1");
		if (row == height - 1 && ft_strlen(map->map[row] - 1) != (width - 1))
			ft_error("Error\nThe map is not rectangular! adios adios 2");
		row++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:57:32 by mhiguera          #+#    #+#             */
/*   Updated: 2023/12/06 16:39:57 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../libft/ft_printf.h"

int    you_win(t_game *game)
{
    int i;
    char *str;

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
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
    exit(1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:57:32 by mhiguera          #+#    #+#             */
/*   Updated: 2023/11/21 18:12:21 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int    you_win(t_game game)
{
    int i;
    char *str;

    i = 0;
    str = "You Won. Congrats!";
    if (game.coins == 0)
    {
        write(1, str, 18);
        exit(0);
    }
    return (0);
}
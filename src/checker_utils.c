/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:57:32 by mhiguera          #+#    #+#             */
/*   Updated: 2023/10/30 19:46:22 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void count_items(char **map, int height)
{
    int collectables;
    int collected;
    int player;
    int num_exit;
    int exit;

    collectables = 0;
    collected = 0;
    player = 0;
    num_exit = 0;
    exit = 0;
    if (collectables < 1)
        ft_error("Not enough collectables!");
    if (num_exit != 1)
        ft_error("There's more than one exit");
    if (player != 1)
        ft_error("There's more than one player");
    //if (collected == collectables && exit == 1);
        //fin del juego has ganado enhorabuena
}
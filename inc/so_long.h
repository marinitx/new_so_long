/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:11:58 by mhiguera          #+#    #+#             */
/*   Updated: 2023/10/15 17:30:57 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#   define SO_LONG_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../gnl/get_next_line.h"
#include "../mlx/mlx.h"

typedef struct s_map {
    void *mlx;
    char **map;
    int img_width;
    int img_height;
    void    *mlx_win;
	void    *img;
    void    *floor;
    void    *collect;
    void    *exit;
    void    *player_y;
    void    *player_x;
    
    

}   t_map;

void	ft_error(char *str);

#endif
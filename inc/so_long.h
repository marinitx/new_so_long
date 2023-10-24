/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:11:58 by mhiguera          #+#    #+#             */
/*   Updated: 2023/10/23 18:54:51 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#   define SO_LONG_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"

typedef struct s_map {
    void *mlx;
    char **map;
    int     width;
    int     height;
    void    *mlx_win;
	void    *img;
    void    *floor;
    void    *collect;
    void    *exit;
    void    *player_y;
    void    *player_x;
    
    

}   t_map;

void	ft_error(char *str);
void	check_extension(char *argv);
void    read_map(char *argv);
void    check_borders(char **map, int height);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:11:58 by mhiguera          #+#    #+#             */
/*   Updated: 2023/10/15 15:32:37 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../gnl/get_next_line.h"
#include "../mlx/mlx.h"

#ifndef SO_LONG_H
#   define SO_LONG_H
typedef struct s_map {
    void *mlx;
    void *win;
    char **map;
    int img_width;
    int img_height;
    

}   t_map;
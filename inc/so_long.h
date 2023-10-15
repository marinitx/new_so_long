/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:11:58 by mhiguera          #+#    #+#             */
/*   Updated: 2023/10/15 14:30:21 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../mlx/mlx.h"

typedef struct s_map {
    void *mlx;
    void *win;
    char **map;
    int img_width;
    int img_height;
    

}   t_map;
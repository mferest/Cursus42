/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_drow_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:30:38 by manufern          #+#    #+#             */
/*   Updated: 2023/12/27 11:44:09 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "math.h"
#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void ft_drow(t_map *map, float center_x, float center_y)
{
    void *mlx;
    void *mlx_win;
    t_data img;
    t_map *map_aux;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "FDF");
    img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    map_aux = map;
    while (map_aux) {
        map_aux->x_rotate = (((map_aux->x - map_aux->y) * cos(ANGULE)) * SCALE_FACTOR);
        map_aux->y_rotate = ((map_aux->x + map_aux->y) * sin(ANGULE) - map_aux->z) * SCALE_FACTOR;
        if (map_aux->x_rotate + center_x <= WIDTH && map_aux->y_rotate + center_y <= HEIGHT 
            && map_aux->x_rotate + center_x >= 0 && map_aux->y_rotate + center_y >= 0)
            printf("color antes de dibujar: %s\n", map_aux->color);
            my_mlx_pixel_put(&img, map_aux->x_rotate + center_x, map_aux->y_rotate + center_y, map_aux->color);
        map_aux = map_aux->next;
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}

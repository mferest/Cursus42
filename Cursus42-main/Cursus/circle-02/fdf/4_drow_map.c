/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_drow_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:30:38 by manufern          #+#    #+#             */
/*   Updated: 2023/12/26 14:12:21 by manufern         ###   ########.fr       */
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
void ft_drow_pixel(int x, int y)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    static int i = 1;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
    img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                &img.endian);
            my_mlx_pixel_put(&img, x, y, 0xFFFFFF);


    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    i++;
    mlx_loop(mlx);
}


void ft_drow(t_map *map, float center_x, float center_y)
{
    void *mlx;
    void *mlx_win;
    t_data img;
    t_map *map_aux;
    float final_coord[2];

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
    img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    map_aux = map;
    while (map_aux) {
        final_coord[0] = (map_aux->x - map_aux->y) * cos(ANGULE);
        final_coord[1] = (map_aux->x + map_aux->y) * sin(ANGULE) - map_aux->z;
        final_coord[0] *= SCALE_FACTOR;
        final_coord[1] *= SCALE_FACTOR;
        my_mlx_pixel_put(&img, final_coord[0] + center_x, final_coord[1] + center_y, 0xFFFFFF);
        map_aux = map_aux->next;
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}

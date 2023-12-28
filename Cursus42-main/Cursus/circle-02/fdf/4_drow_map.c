/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_drow_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:30:38 by manufern          #+#    #+#             */
/*   Updated: 2023/12/28 13:34:10 by manuel           ###   ########.fr       */
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

void ft_drow_line(t_map *map, int center_x, int center_y, t_data *img)
{
    t_map   *line1;
    t_map   *line2;

    line1 = map;
    line2 = map;
    while (line2 != NULL && line2->y != 1)
    {
        line2 = line2->next;
    }
    while (line2 || ( line1 && line1->next))
    {
        if (line1->next != NULL && line1->y == line1->next->y)
            line_bresenham(img, line1->x_rotate + center_x, line1->y_rotate + center_y, line1->next->x_rotate + center_x, line1->next->y_rotate + center_y, line1->color, line1->next->color);
        if (line2)
            line_bresenham(img, line1->x_rotate + center_x, line1->y_rotate + center_y, line2->x_rotate + center_x, line2->y_rotate + center_y, line1->color, line2->color);
        line1 = line1->next;
        if (line2)
            line2 = line2->next;
    }
}

void ft_drow(t_map *map, float center_x, float center_y)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    t_map   *map_aux;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "FDF");
    img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    map_aux = map;
    while (map_aux)
    {
        if (map_aux->x_rotate + center_x <= WIDTH && map_aux->y_rotate + center_y <= HEIGHT 
            && map_aux->x_rotate + center_x >= 0 && map_aux->y_rotate + center_y >= 0)
            my_mlx_pixel_put(&img, map_aux->x_rotate + center_x, map_aux->y_rotate + center_y, map_aux->color);
        map_aux = map_aux->next;
    }
    ft_drow_line(map, center_x, center_y, &img);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}

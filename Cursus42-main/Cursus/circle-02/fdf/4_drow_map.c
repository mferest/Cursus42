/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_drow_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:30:38 by manufern          #+#    #+#             */
/*   Updated: 2023/12/27 18:25:06 by manufern         ###   ########.fr       */
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

int ft_scale_x(t_map **map)
{
    t_map *map_aux = *map;
    int x_max = 0;
    int x_min = 2147483647;
    while(map_aux)
    {
        if(x_max < map_aux->x_rotate )
            x_max = map_aux->x_rotate;
        if (x_min < map_aux->x_rotate)
             x_min = map_aux->x_rotate;
        map_aux = map_aux->next;
    }
    return (WIDTH / (x_max - x_min));
}

int ft_scale_y(t_map **map)
{
    t_map *map_aux = *map;
    int y_max = 0;
    int y_min = 2147483647;
    while(map_aux)
    {
        if(y_max < map_aux->y_rotate )
            y_max = map_aux->y_rotate;
        if (y_min < map_aux->y_rotate)
             y_min = map_aux->y_rotate;
        map_aux = map_aux->next;
    }
    return (HEIGHT / (y_max - y_min));
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
    while (map_aux)
    {
        if (map_aux->x_rotate + center_x <= WIDTH && map_aux->y_rotate + center_y <= HEIGHT 
            && map_aux->x_rotate + center_x >= 0 && map_aux->y_rotate + center_y >= 0)
            my_mlx_pixel_put(&img, map_aux->x_rotate + center_x, map_aux->y_rotate + center_y, map_aux->color);
        map_aux = map_aux->next;
    }
    map_aux = map;
    while (map_aux && map_aux->next)
    {
        if (map_aux->next != NULL && map_aux->y == map_aux->next->y)
        {
            line_bresenham(&img, map_aux->x_rotate + center_x, map_aux->y_rotate + center_y, map_aux->next->x_rotate + center_x, map_aux->next->y_rotate + center_y, map_aux->color, map_aux->next->color);
        }
        map_aux = map_aux->next;
    }
    t_map *line1 = map;
    t_map *line2 = map;

    while (line2 != NULL && line2->y != 1)
    {
        line2 = line2->next;
    }
    while (line2)
    {
        line_bresenham(&img, line1->x_rotate + center_x, line1->y_rotate + center_y, line2->x_rotate + center_x, line2->y_rotate + center_y, line1->color, line2->color);
        line1 = line1->next;
        line2 = line2->next;
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}

/* void ft_drow(t_map *map, float center_x, float center_y)
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
    int scale_x = ft_scale_x(&map);
    int scale_y = ft_scale_y(&map); 
    while (map_aux)
    {
        if (map_aux->x_rotate + center_x <= WIDTH && map_aux->y_rotate + center_y <= HEIGHT 
            && map_aux->x_rotate + center_x >= 0 && map_aux->y_rotate + center_y >= 0)
            my_mlx_pixel_put(&img, map_aux->x_rotate * scale_x, map_aux->y_rotate * scale_y, map_aux->color);
        map_aux = map_aux->next;
    }
    map_aux = map;
    while (map_aux && map_aux->next)
    {
        if (map_aux->next != NULL && map_aux->y == map_aux->next->y)
        {
            line_bresenham(&img, map_aux->x_rotate * scale_x, map_aux->y_rotate * scale_y, map_aux->next->x_rotate * scale_x, map_aux->next->y_rotate * scale_y, map_aux->color, map_aux->next->color);
        }
        map_aux = map_aux->next;
    }
    t_map *line1 = map;
    t_map *line2 = map;

    while (line2 != NULL && line2->y != 1)
    {
        line2 = line2->next;
    }
    while (line2)
    {
        line_bresenham(&img, line1->x_rotate * scale_x, line1->y_rotate * scale_y, line2->x_rotate * scale_x, line2->y_rotate * scale_y, line1->color, line2->color);
        line1 = line1->next;
        line2 = line2->next;
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}  */
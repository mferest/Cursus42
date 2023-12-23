/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_drow_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:30:38 by manufern          #+#    #+#             */
/*   Updated: 2023/12/20 18:42:18 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "math.h"
#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

int ft_adjust_y(t_map *map, int window_y)
{
    t_map *map_aux;
    int y_dimension;

    y_dimension = 0;  
    map_aux = map;
    while (map_aux)
    {
        if (map_aux->y > y_dimension)
            y_dimension = map_aux->y; 
        map_aux = map_aux->next;
    }
    return ((window_y / y_dimension) / 4);
}

int ft_adjust_x(t_map *map, int window_x)
{
    t_map *map_aux;
    int x_dimension;

    x_dimension = 0;  
    map_aux = map;
    while (map_aux)
    {
        if (map_aux->x > x_dimension)
            x_dimension = map_aux->x;
        map_aux = map_aux->next;
    }
     return ((window_x / x_dimension) / 4);
}


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
    while (map_aux)
    {
        final_coord[0] = ((map_aux->x - map_aux->y) * cos(ANGULE));
        final_coord[1] = ((map_aux->x + map_aux->y - 2 * map_aux->z) * sin(ANGULE));
        final_coord[0] *= SCALE_FACTOR;
        final_coord[1] *= SCALE_FACTOR;
        my_mlx_pixel_put(&img, final_coord[0] + center_x, final_coord[1] + center_y, 0xFFFFFF);
        map_aux = map_aux->next;
    }

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}

/* void ft_drow(t_map *map)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    t_map  *map_aux;
    float   final_coord[4];

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
    img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    map_aux = map;
    float center_x = WIDTH / 2;
    float center_y = HEIGHT / 2;

    while (map_aux) {
        final_coord[0] = (map_aux->x * ft_adjust_x(map, WIDTH));
        final_coord[1] = ((map_aux->y - map_aux->z) * ft_adjust_y(map, HEIGHT));

        // Precompute sine and cosine for better performance
        float sin_theta = sin(ANGULE);
        float cos_theta = cos(ANGULE);

        final_coord[2] = final_coord[0] * cos_theta - final_coord[1] * sin_theta;
        final_coord[3] = final_coord[0] * sin_theta + final_coord[1] * cos_theta;

        my_mlx_pixel_put(&img, final_coord[2] + center_x, final_coord[3] + center_y, 0xFFFFFF);
        map_aux = map_aux->next;
    }

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
} */




// Función para dibujar una línea (Bresenham's Line Algorithm)







/*
    Formula dubujar en isometrico.
    double isometric_x = (sqrt(2) / 2) * (x - z);
    double isometric_y = (sqrt(2) / 2) * (y + x + z);

   float *X_iso = (x - z) / sqrt(2);
    float *Y_iso = (y - z) / sqrt(2);

    *X_iso = (sqrt(3) / 2) * x - (sqrt(3) / 2) * z;
    *Y_iso = 0.5 * x + 0.5 * y - z;

    *X_iso = (sqrt(2) / 2) * (x - z);
    *Y_iso = (sqrt(6) / 3) * y + (sqrt(2) / 2) * (x + z);

    float Xiso = (x - z) / sqrt(2);
    float Yiso = (y + 2 * z) / sqrt(6);

    float Xiso = (map_aux->x - map_aux->z) / sqrt(2);
    float Yiso = (map_aux->x + 2 * map_aux->y + map_aux->z) / sqrt(6);

   *X_iso = map_aux->x - map_aux->z * cos(theta);
    *Y_iso = map_aux->y - map_aux->z * sin(theta); 
    x * sin(theta) + y * sin(theta)

    map_aux->x * cos(ANGULE) - map_aux->y * cos(ANGULE)
     map_aux->x * sin(ANGULE) +  map_aux->y * sin(ANGULE)
*/
/* t_map *map_aux = map; 

        while (map_aux)
        {
            ft_drow_pixel(map_aux->x, map_aux->y); 
            map_aux = map_aux->next;
        } */
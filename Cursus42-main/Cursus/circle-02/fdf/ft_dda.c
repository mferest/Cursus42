/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:55:10 by manuel            #+#    #+#             */
/*   Updated: 2023/12/29 12:46:42 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "math.h"
#include <float.h>
#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

t_dda_params set_dda_params(t_map *p1, t_map *p2, float center_x, float center_y)
{
    t_dda_params params;
    params.dx = p2->x_rotate - p1->x_rotate;
    params.dy = p2->y_rotate - p1->y_rotate;

    if (fabs(params.dx) > fabs(params.dy))
        params.steps = fabs(params.dx);
    else
        params.steps = fabs(params.dy);
    params.incx = params.dx / params.steps;
    params.incy = params.dy / params.steps;
    params.x = p1->x_rotate + center_x;
    params.y = p1->y_rotate + center_y;
    return (params);
}

void ft_dda(t_data *img, t_dda_params params, int color1, int color2)
{
    int i = 0;
    while (i <= params.steps)
    {
        my_mlx_pixel_put(img, round(params.x), round(params.y), color1);
        params.x += params.incx;
        params.y += params.incy;
        i++;
    }
}

/* void ft_dda(t_data *img, int x1, int y1, int x2, int y2, int color)
{
    dda_params  params;
    int         i;

    params.dx = x2 - x1;
    params.dy = y2 - y1;
    if (fabs(params.dx) > fabs(params.dy))
        params.steps = fabs(params.dx);
    else
        params.steps = fabs(params.dy);
    params.incx = params.dx / params.steps;
    params.incy = params.dy / params.steps;
    params.x = x1;
    params.y = y1;
    i = 0;
    while (i <= params.steps)
    {
        my_mlx_pixel_put(img, round(params.x), round(params.y), color);
        params.x += params.incx;
        params.y += params.incy;
        i++;
    }
} */

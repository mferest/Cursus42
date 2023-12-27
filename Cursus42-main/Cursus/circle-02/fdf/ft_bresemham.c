/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresemham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:10:16 by manufern          #+#    #+#             */
/*   Updated: 2023/12/27 15:38:54 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "math.h"
#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

int interpolate_color(int color0, int color1, int x0, int y0, int x1, int y1, int x, int y)
{
    double t = (double)(x - x0) / (double)(x1 - x0);
    int r0 = (color0 >> 16) & 0xFF;
    int g0 = (color0 >> 8) & 0xFF;
    int b0 = color0 & 0xFF;

    int r1 = (color1 >> 16) & 0xFF;
    int g1 = (color1 >> 8) & 0xFF;
    int b1 = color1 & 0xFF;

    int r = (int)(r0 + t * (r1 - r0));
    int g = (int)(g0 + t * (g1 - g0));
    int b = (int)(b0 + t * (b1 - b0));

    return (r << 16) | (g << 8) | b;
}

void line_bresenham(t_data *img, int X1, int Y1, int X2, int Y2, int color0, int color1)
{
    int dY = abs(Y2 - Y1);
    int dX = abs(X2 - X1);
    int IncYi, IncXi;

    if (Y1 < Y2)
    {
        IncYi = 1;
    }
    else
    {
        IncYi = -1;
    }

    if (X1 < X2)
    {
        IncXi = 1;
    }
    else
    {
        IncXi = -1;
    }

    int IncXr, IncYr;
    if (dX >= dY)
    {
        IncYr = 0;
        IncXr = IncXi;
    }
    else
    {
        IncXr = 0;
        IncYr = IncYi;
        int k = dX;
        dX = dY;
        dY = k;
    }

    int X = X1, Y = Y1;
    int avR = (2 * dY);
    int av = (avR - dX);
    int avI = (av - dX);

    do
    {
        if (X >= 0 && X < WIDTH && Y >= 0 && Y < HEIGHT)
        {
            int interpolated_color = interpolate_color(color0, color1, X1, Y1, X2, Y2, X, Y);
            my_mlx_pixel_put(img, X, Y, interpolated_color);
        }

        if (av >= 0)
        {
            X = (X + IncXi);
            Y = (Y + IncYi);
            av = (av + avI);
        }
        else
        {
            X = (X + IncXr);
            Y = (Y + IncYr);
            av = (av + avR);
        }
    } while (X != X2 || Y != Y2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_get_line_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:06:40 by manufern          #+#    #+#             */
/*   Updated: 2023/12/27 11:59:55 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

int ft_has_color(char *map_line)
{
    int i;

    i = 0;
    while (map_line[i] != '\0')
    {
        if (map_line[i] == ',')
            return (1); //tiene color
        i ++;
    }
    return (0);
}

void ft_send_coord(int x, int y, int z, char *map_line)
{
    char    **num_color;
    char    *color;
    char    *num;
    
    if (ft_has_color(map_line) == 1)
    {
        num_color = ft_split(map_line, ',');
        if (num_color == NULL)
            exit (0);
        z = ft_atoi(num_color[0]);
        color = ft_strcpy_to_char(num_color[1], '\n');
        create_list(x, y, z, color);
        free (color);
        ft_free(num_color, 2);
    }
   else
    {
        num = malloc(sizeof(char) * ft_strlen(map_line) + 1);
        if (num == NULL)
            exit(0);
        num = ft_strcpy_to_char(map_line, '\n');
        z = ft_atoi(num);
        create_list(x, y, z, "0xFFFFFF");
        free (num);
    }
}

void ft_div_line(char const *line)
{   
    char        **map_line;
    int         i;
    int         x;
    int         z;
    static int  y = 0;
    
    z = 0;
    i = 0;
    x = 0;
    map_line = ft_split(line, ' ');
    while (map_line != NULL && map_line[i])
    {
        ft_send_coord(x, y, z, map_line[i]);
        i++;
        x = x + 1; // Considerar ajuste según la longitud real de la línea
    }
    y = y + 1;
    ft_free(map_line, i);
}

int ft_get_line_map(char *argv)
{
    char *line;
    int fd;
    
    fd = open(argv, O_RDONLY);
    if (fd == -1)
    {
        printf("Error al abrir el archivo");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        ft_div_line(line);
        free (line);
    }
    printf("nodo ultimo\n");
    create_list(234345, 234345, 234345, "FFFFFF");
    return (0);
}

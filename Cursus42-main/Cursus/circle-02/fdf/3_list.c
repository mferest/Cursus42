/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:17:27 by manufern          #+#    #+#             */
/*   Updated: 2023/12/28 16:07:30 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

void ft_point_down(t_map **map)
{
    t_map *line1 = *map;
    t_map *line2 = *map;

    while (line2 != NULL && line2->y != 1)
    {
        line2 = line2->next;
    }

    while (line2)
    {
        line1->down = line2;
        line1 = line1->next;
        line2 = line2->next;
    }
}

t_map *new_map_node(int x, int y, int z, char *color)
{
    t_map *new_node = malloc(sizeof(t_map));
    
    if (new_node == NULL)
    {
        return NULL;
    }
    new_node->x = x;
    new_node->y = y;
    new_node->z = z;
    new_node->color = ft_atoi_hexa(color);
    new_node->next = NULL;
    new_node->down = NULL;
    new_node->x_rotate = (((x - y) * cos(ANGULE))) * SCALE_FACTOR;
    new_node->y_rotate = ((x + y) * sin(ANGULE) - (z)) * SCALE_FACTOR;
    return new_node;
}
void ft_lstadd_back_map(t_map **lst, t_map *new)
{
    t_map *tmp;
    
    if (*lst == NULL)
    {
        *lst = new;
    } 
    else {
        tmp = *lst; 
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}

void create_list(int x, int y, int z, char *color)
{
    t_map *new_node ;
    static	t_map *map = NULL;
    
    new_node = NULL;
    if (x == 234345 && y == 234345 && z == 234345)
    {
		ft_point_down(&map);
        printf("%d", map->down->y);
        ft_drow(map, WIDTH / 2, HEIGHT / 2);
    }
    else
    {
        new_node = new_map_node(x, y, z, color);
        ft_lstadd_back_map(&map, new_node);
        return ;
    }
    ft_free_s_map (&map);
}

/* t_map *map_aux = map;
        int i = 1; 

        while (map_aux)
        {
            printf("Nodo %d:\n", i); 
            printf("Color: %s\n", map_aux->color);
            printf("X: %d\n", map_aux->x);
            printf("Y: %d\n", map_aux->y);
            printf("Z: %d\n", map_aux->z);

            // Agregar un salto de línea entre nodos para mejorar la legibilidad
            printf("\n");

            i++;
            map_aux = map_aux->next;
        } */

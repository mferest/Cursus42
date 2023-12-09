/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_argument_to_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:03:25 by manufern          #+#    #+#             */
/*   Updated: 2023/12/09 18:59:35 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void argument_to_list(char *map)
{
    char **map_split;
    char **num_color;
    
    map_split = ft_split(map, ' ');
    free (map);
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (map_split[i] != NULL)
    {
        j = ft_color (map_split, i);
        if (j == 1)
        {
            printf("yes\n");
            ft_yes_color(i, map_split);
        }
        else
            printf("no");
        printf("%s\n", map_split[i]); //para pruebas
        i ++;
    }
    ft_free(map_split, i);
}

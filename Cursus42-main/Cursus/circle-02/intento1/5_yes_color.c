/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_yes_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:31:30 by manufern          #+#    #+#             */
/*   Updated: 2023/12/09 18:45:03 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_yes_color(int i, char **map_split)
{
    char **num_color;
    
    num_color = ft_split(map_split[i], ',');
    printf("numero %s\n", num_color[0]);
    printf("color %s\n", num_color[1]);
    
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_get_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:06:40 by manufern          #+#    #+#             */
/*   Updated: 2023/12/09 21:58:32 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

void ft_div_line(char const *line)
{   
    char **map_line;
    int i = 0;
    
    map_line = ft_split(line, ' ');
    while(map_line[i])
    {
        printf("%s\n", map_line[i]);
        i ++;
    }
    ft_free(map_line, i);
}

int ft_get_line(char *argv)
{
    char *line;
    int fd;
    
    fd = open(argv, O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        ft_div_line(line);
        free (line);
    }
    return (0);
}

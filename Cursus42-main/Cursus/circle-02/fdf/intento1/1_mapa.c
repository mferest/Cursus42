/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:12:09 by manufern          #+#    #+#             */
/*   Updated: 2023/12/09 18:17:52 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void    ftliks()
{
    system("leaks -q a.out");  
}
int	main(int argc, char **argv)
{
    char    *map;
    char    **num;

    if (argc != 2)
    {
        printf("ERROR\n");
        return (-1);
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }
    map = ft_get_map(fd);
    close(fd);
    printf("%s\n", map); //para pruebas
    argument_to_list(map);
    /* atexit(ftliks); */
    return 0;
}

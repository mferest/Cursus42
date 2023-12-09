/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:58:38 by manufern          #+#    #+#             */
/*   Updated: 2023/12/09 21:51:10 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

void    ftliks()
{
    system("leaks -q a.out");  
}

int	main(int argc, char **argv)
{
    atexit(ftliks);
    char    *map;
    char    **num;

    if (argc != 2)
    {
        printf("ERROR\n");
        return (-1);
    }
    ft_get_line(argv[1]);
    
}
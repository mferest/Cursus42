/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:58:38 by manufern          #+#    #+#             */
/*   Updated: 2023/12/29 12:36:31 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

void	ft_liks(void)
{
	system("leaks -q a.out");
}

int	main(int argc, char **argv)
{
	/* atexit(ft_liks); */
	if (argc != 2)
	{
		return (-1);
	}
	ft_get_line_map(argv[1]);
	return (0);
}

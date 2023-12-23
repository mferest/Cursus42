/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:44:04 by manufern          #+#    #+#             */
/*   Updated: 2023/12/23 11:09:35 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#ifndef WIDTH
#define WIDTH 1920
#endif
#ifndef HEIGHT
#define HEIGHT 1080
#endif
#ifndef ANGULE
#define ANGULE (0.523599)
#endif
#ifndef SCALE_FACTOR 
#define SCALE_FACTOR 20.0
#endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "math.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

typedef struct s_map
{
  int           x;
  int           y;
  int           z;
  char          *color;
  struct s_map  *next;
  struct s_map  *down;
}				t_map;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void ft_send_coord(int x, int y, int z, char *map_line);
int ft_get_line_map(char *argv);
int	main(int argc, char **argv);
t_map *new_map_node(int x, int y, int z, char *color);
void create_list(int x, int y, int z, char *color);
void ft_lstadd_back_map(t_map **lst, t_map *new);
void  ft_free_s_map(t_map **map);
void ft_drow(t_map *map, float center_x, float center_y);
/* void ft_drow_pixel(int x, int y); */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int ft_adjust_x(t_map *map, int);
int ft_adjust_y(t_map *map, int window_y);
int ft_adjust_x(t_map *map, int window_x);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
void ft_drow_pixel(int x, int y);
#endif
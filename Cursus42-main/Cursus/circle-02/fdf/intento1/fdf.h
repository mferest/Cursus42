/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:44:04 by manufern          #+#    #+#             */
/*   Updated: 2023/12/09 18:41:17 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_strlen(const char *str);
void    ft_yes_color(int i, char **map_split);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_get_map(int fd);
int ft_string_count(char const *s, char c);
int	ft_word_count(char const *s, char c, int i);
char	**ft_free(char **aux, int j);
char	**ft_matrix(char **aux, char const *s, char c, int i);
char	**ft_split(char const *s, char c);
int ft_color(char **map, int i);
void argument_to_list(char *map);
int	main(int argc, char **argv);
#endif
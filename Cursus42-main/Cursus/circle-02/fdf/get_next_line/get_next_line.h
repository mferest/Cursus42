/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:56:55 by manufern          #+#    #+#             */
/*   Updated: 2023/12/09 21:09:00 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include<limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
size_t	ft_strlen_mod(char *s);
char	*ft_strjoin_mod(char *s1, char *s2);
char	*ft_strdup_mod(char *s1);
char	*ft_strchr_mod(char *s, int c);
char	*ft_substr_mod(char *s);
#endif

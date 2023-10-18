/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:50:39 by manufern          #+#    #+#             */
/*   Updated: 2023/10/18 20:03:18 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 14
#endif
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*dupl;
	int		i;

	i = 0;
	dupl = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dupl)
		return (NULL);
	while (s1[i] != '\0')
	{
		dupl[i] = s1[i];
		i ++;
	}
	dupl[i] = '\0';
	return (dupl);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(const char *s)
{
	size_t	count;
	char	*str;
	size_t	i;

	str = NULL;
	i = 0;
	count = 0;
	while (s[count] != '\n' && s[count] != '\0')
		count++;
	str = malloc(count + 2);
	if (!str)
		return (NULL);
	while (s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\n';
	i++;
	str[i] = '\0';
	return (str);
}

int	ft_found_line(const char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_copy(const char *frag, int bytes_read)
{
	char	*aux;
	int		i;

	i = 0;
	aux = malloc(bytes_read + 1);
	while (i < bytes_read)
	{
		aux[i] = frag[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

char	*ft_read(int fd, char *buffer, int *bytes_read)
{
	char frag[BUFFER_SIZE + 1];
	char *tmp;
	int i;

	i = 0;
	*bytes_read = read(fd, frag, BUFFER_SIZE);
	if(*bytes_read > 0)
		frag[*bytes_read] = '\0';
	if (*bytes_read <= 0)
	{
		if (buffer)
			return(buffer);
		return (NULL);
	}
	if (!buffer)
	{
		return (ft_copy(frag, *bytes_read));
	}
	else
	{
		tmp = ft_strjoin(buffer, frag);
		return (tmp);
	}
}

char	*get_next_line(int fd)
{
	static char *buffer = NULL;
	char *line;
	int yes_no;
	int bytes_read;

	yes_no = 2;
	bytes_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read(fd, buffer, &bytes_read);
	if (buffer == NULL)
		return (NULL);
	if (bytes_read == 0 && ft_strlen(buffer) == 0)
		return (NULL);
	if (bytes_read < BUFFER_SIZE)
	{
		line = ft_strdup(buffer);
		buffer = NULL;
		return (line);
	}
	yes_no = ft_found_line(buffer);
	if (yes_no == 1)
	{
		line = ft_substr(buffer);
		buffer = ft_strchr(buffer, '\n') + 1;
		return (line);
	}
	return (get_next_line(fd));
}

int	main(void)
{
	int fd = open("cancion.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return 1;
	}

	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
	return 0;
}

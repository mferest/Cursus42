/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:42:50 by manufern          #+#    #+#             */
/*   Updated: 2023/10/21 12:28:54 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_found_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	if (i > 0)
		return (2);
	return (0);
}

char	*ft_copy(char *frag, int bytes_read)
{
	char	*aux;
	int		i;

	i = 0;
	aux = NULL;
	aux = malloc(bytes_read + 1);
	if (!aux)
	{
		return (NULL);
	}
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
	char	frag[BUFFER_SIZE + 1];
	char	*tmp;

	*bytes_read = read(fd, frag, BUFFER_SIZE);
	if (*bytes_read > 0)
		frag[*bytes_read] = '\0';
	if (*bytes_read <= 0)
	{
		if (buffer)
			return (buffer);
		return (NULL);
	}
	if (!buffer)
	{ 
		tmp = ft_copy(frag, *bytes_read);
	}
	else
	{
		tmp = ft_strjoin(buffer, frag);
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	int			yes_no;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (line = NULL);
	buffer = ft_read(fd, buffer, &bytes_read);
	if (buffer[0] == '\0')
		return (NULL);
	yes_no = ft_found_line(buffer);
	if (yes_no == 1)
	{
		line = ft_substr(buffer);
		buffer = ft_strchr(buffer, '\n') + 1;
		return (line);
	}
	if (yes_no == 2 && bytes_read < BUFFER_SIZE)
	{
		line = ft_copy(buffer, ft_strlen(buffer));
		buffer[0] = '\0';
		return (line);
	}
	return (get_next_line(fd));
}

int	main(void)
{
	int fd = open("cancion", O_RDONLY);
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
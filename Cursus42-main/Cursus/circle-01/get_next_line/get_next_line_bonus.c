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

char *next_line(char *buffer)
{
	char *tmp;
	
	tmp = ft_strchr(buffer, '\n') + 1;
	if (ft_strlen(tmp) > 0)
	{
		tmp = ft_strdup(tmp);
	}
	else
	{
	tmp = NULL;
	}
	if (buffer != NULL)
	{
		free(buffer);
	}
	return (tmp);
}
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

char	*ft_read(int fd, char *buffer, int *bytes_read)
{
	char	frag[BUFFER_SIZE + 1];
	char	*tmp;

	if(read(fd, 0, 0) < 0)
	{
		free (buffer);
		return (NULL);
	}
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
		tmp = ft_strdup(frag);
	}
	else
	{
		tmp = ft_strjoin(buffer, frag);
		free(buffer);
	}
	return (tmp);
} 

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;
	int			has_line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (line = NULL);
	buffer[fd] = ft_read(fd, buffer[fd], &bytes_read);
	if (buffer[fd] == NULL)
		return (NULL);
	has_line = ft_found_line(buffer[fd]);
	if (has_line == 1)
	{
		line = ft_substr(buffer[fd]);
		if (!line)
			return(free(buffer[fd]), buffer[fd] = NULL, NULL);
		return (buffer[fd] = next_line(buffer[fd]), line);
	}
	if (has_line == 2 && bytes_read < BUFFER_SIZE)
	{
		line = ft_strdup(buffer[fd]);
			return(free(buffer[fd]), buffer[fd] = NULL, line);
	}
	return (get_next_line(fd));
}
/* int	main(void)
 {
	int fd = open("giant_line_nl.txt", O_RDONLY);
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
}  */

/* int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("cancion", O_RDONLY);
	fd2 = open("big_line_no_nl", O_RDONLY);
	fd3 = open("giant_line.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */
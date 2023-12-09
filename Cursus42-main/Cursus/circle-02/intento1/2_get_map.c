/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:17:56 by manufern          #+#    #+#             */
/*   Updated: 2023/12/09 16:48:45 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_strlen(const char *str)
{
    size_t len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

char	*ft_strjoin(char *s1, char *s2)
{
    if (!s1 || !s2)
        return (NULL);

    size_t	len1 = ft_strlen(s1);
    size_t	len2 = ft_strlen(s2);
    char	*str = (char *)malloc(len1 + len2 + 1);

    if (!str)
        return (NULL);

    size_t	i = 0;
    while (i < len1)
    {
        str[i] = s1[i];
        i++;
    }

    size_t j = 0;
    while (j < len2)
    {
        str[i++] = s2[j++];
    }

    str[i] = '\0';
    return (str);
}

char	*ft_strdup(const char *s1)
{
    size_t	len = ft_strlen(s1);
    char	*dupl = (char *)malloc(len + 1);

    if (!dupl)
        return (NULL);

    size_t	i = 0;
    while (i < len)
    {
        dupl[i] = s1[i];
        i++;
    }

    dupl[i] = '\0';
    return (dupl);
}

char	*ft_get_map(int fd)
{
    char	frag[101]; // Asegúrate de tener espacio para el caracter nulo.
    char	*map = NULL;
    ssize_t	bytes_read;

    while ((bytes_read = read(fd, frag, 100)) > 0)
    {
        frag[bytes_read] = '\0'; // Asegúrate de terminar la cadena.
        if (!map)
            map = ft_strdup(frag);
        else
        {
            char *tmp = ft_strjoin(map, frag);
            free(map);
            map = tmp;
        }
    }

    if (bytes_read < 0)
    {
        perror("Error al leer el archivo");
        free(map); // Liberar la memoria antes de salir.
        return NULL;
    }
    return (map);
}

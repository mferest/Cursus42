/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:30:30 by manufern          #+#    #+#             */
/*   Updated: 2023/09/27 17:20:43 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* comprueba si una cadena esta dentro de otra hasta n bites*/
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j]
			&& haystack[i + j] != '\0' && (i + j) < len)
			j ++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i ++;
	}
	return (NULL);
}

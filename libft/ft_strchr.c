/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:09:06 by manufern          #+#    #+#             */
/*   Updated: 2023/09/19 18:41:50 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*en cuentra el caracter quiero buscar en un string y
devuelve un puntero apuntendo a esa letra se no la encuentra devuelve null*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char )c)
			return ((char *)s);
		s++;
	}
	if (*s == (char )c)
		return ((char *)s);
	return (NULL);
}

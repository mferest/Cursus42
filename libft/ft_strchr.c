/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:09:06 by manufern          #+#    #+#             */
/*   Updated: 2023/09/15 17:28:42 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*en cuentra el caracter quiero buscar en un string y
devuelve un puntero apuntendo a esa letra se no la encuentra devuelve null*/

char	*strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char )c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

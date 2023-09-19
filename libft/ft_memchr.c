/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:10:31 by manufern          #+#    #+#             */
/*   Updated: 2023/09/18 19:34:48 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* me devuelve un puntero que apunta a la primera aparicion del caracter
 que quiero buscar*/
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*f;
	char				ch;

	f = s;
	ch = (unsigned char )c;
	while (n > 0 && *f != '\0')
	{
		if (*f == ch)
			return ((void *)f);
		f ++;
		n --;
	}
	return (NULL);
}

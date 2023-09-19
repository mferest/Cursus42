/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:44:10 by manufern          #+#    #+#             */
/*   Updated: 2023/09/18 18:43:26 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* compara una cadena con otra hasta la posicion que yo le diga
 devuelve un cero si son iguales y u numero si son distintas*/
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*chs1;
	const char	*chs2;

	chs1 = s1;
	chs2 = s2;
	while (chs1 == chs2 && n > 0)
	{
		chs1 ++;
		chs2 ++;
		n --;
	}
	return (chs1 - chs2);
}

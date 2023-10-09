/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:36:08 by manufern          #+#    #+#             */
/*   Updated: 2023/09/19 19:33:50 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst < src)
	{
		while (len --)
			*d++ = *s++;
	}
	else if (d > s)
	{
		d += len;
		s += len;
		while (len --)
			*(--d) = *(--s);
	}
	return (dst);
}

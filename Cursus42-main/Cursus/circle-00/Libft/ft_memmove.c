/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:12:30 by manufern          #+#    #+#             */
/*   Updated: 2023/10/02 17:27:28 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	s = src;
	d = dst;
	i = 0;
	if (d < s)
	{
		while (i < len)
		{
			d[i] = s[i];
			i ++;
		}
	}
	else if (d > s)
	{
		i = len;
		while (i > 0)
		{
			i --;
			d[i] = s[i];
		}
	}
	return (dst);
}

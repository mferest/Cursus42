/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:10:31 by manufern          #+#    #+#             */
/*   Updated: 2023/09/19 20:08:03 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*f;
	unsigned char	ch;
	size_t			i;

	f = (unsigned char *)s;
	i = 0;
	ch = (unsigned char )c;
	while (i < n)
	{
		if (f[i] == ch)
			return ((void *)&f[i]);
		i ++;
	}
	return (NULL);
}

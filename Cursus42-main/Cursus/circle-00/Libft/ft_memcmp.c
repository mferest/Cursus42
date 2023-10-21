/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:44:10 by manufern          #+#    #+#             */
/*   Updated: 2023/09/20 13:11:08 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*chs1;
	const unsigned char	*chs2;

	chs1 = s1;
	chs2 = s2;
	while (n > 0)
	{
		if (*chs1 != *chs2)
			return (*chs1 - *chs2);
		chs1 ++;
		chs2 ++;
		n --;
	}
	return (0);
}

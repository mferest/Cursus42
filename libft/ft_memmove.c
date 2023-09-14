/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:36:08 by manufern          #+#    #+#             */
/*   Updated: 2023/09/14 19:08:41 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst < src || d > s + len)
	{
		while (len --)
			*d++ = *s++;
	}
	else
	{
		d += len;
		s += len;
		while (len --)
			*d-- = *s--;
	}
	return (dst);
}

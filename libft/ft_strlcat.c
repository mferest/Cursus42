/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:41:04 by manufern          #+#    #+#             */
/*   Updated: 2023/09/20 12:56:15 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	j = 0;
	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] != '\0')
		dst_len ++;
	while (src[src_len] != '\0')
		src_len ++;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (src[j] != '\0' && dst_len + j < dstsize - 1)
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	dst[dst_len + j] = '\0';
	return (dst_len + src_len);
}

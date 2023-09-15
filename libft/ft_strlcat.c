/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:41:04 by manufern          #+#    #+#             */
/*   Updated: 2023/09/15 17:32:02 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	j = 0;
	l = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	l = dstsize - i;
	if (dstsize == 0 || src[j] == '\0')
		return (i);
	while (src != "\0" && j < l)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + j);
}

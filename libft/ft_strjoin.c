/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:25:27 by manufern          #+#    #+#             */
/*   Updated: 2023/09/22 16:58:36 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_strlcat2(char *dst, const char *src, size_t dstsize)
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
		return ((char *)dst);
	while (src[j] != '\0' && dst_len + j < dstsize - 1)
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	dst[dst_len + j] = '\0';
	return ((char *)dst);
}

#include <stdio.h>
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	count;
	char	*str;

	count = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(count + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	printf("%s\n%zu\n%zu", str, ft_strlen(s1), ft_strlen(s2)); 
	ft_strlcat2(str, s2, ft_strlen(s2) + 1);
	
	printf("%s\n%zu\n%zu", str, ft_strlen(s1), ft_strlen(s2)); 
	return (str);
}
#include <stdio.h>
int main()
{
	char *a = "hola,";
	char *b = "adios";
	char *p;
	p = ft_strjoin(a, b);
	printf("%s\n", p);
	return (0);
}

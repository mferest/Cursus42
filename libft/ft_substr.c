/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:37:40 by manufern          #+#    #+#             */
/*   Updated: 2023/09/22 14:21:17 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	char	*str;
	size_t	i;

	str = NULL;
	i = 0;
	count = ft_strlen(s);
	if (start >= count || len == 0)
		return (ft_strdup(""));
	if (len > count - start)
		len = count - start;
		str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (s[start] != '\0' && len > 0)
	{
		str[i] = s[start];
		start ++;
		i ++;
		len --;
	}
	str[i] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:08:24 by manufern          #+#    #+#             */
/*   Updated: 2023/09/23 19:41:24 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_start(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (ft_strchr(set, s1[i]) != NULL && s1[i] != '\0')
		i++;
	return (i);
}

static int	find_end(const char *s1, const char *set, int start)
{
	int	j;

	j = start;
	while (s1[j] != '\0')
		j++;
	j = j - 1;
	while (ft_strchr(set, s1[j]) != NULL && j >= 0)
		j--;
	return (j);
}

static char	*create_trimmed_str(const char *s1, int start, int end)
{
	int		len;
	char	*str;
	int		i;
	int		k;

	len = end - start + 1;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = start;
	k = 0;
	while (i <= end)
	{
		str[k] = s1[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	char	*str;
	int		end;

	start = find_start(s1, set);
	if (s1[start] == '\0')
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	end = find_end(s1, set, start);
	return (create_trimmed_str(s1, start, end));
}

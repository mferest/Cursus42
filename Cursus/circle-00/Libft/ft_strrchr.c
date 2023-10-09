/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:46:54 by manufern          #+#    #+#             */
/*   Updated: 2023/09/30 17:46:38 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		found;
	char		*end;

	end = (char *)s;
	found = (char )c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (end[i] == found)
			return (end + i);
		i --;
	}
	if (end[i] == found)
		return (end);
	return (NULL);
}

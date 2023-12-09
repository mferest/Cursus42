/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:11:12 by manufern          #+#    #+#             */
/*   Updated: 2023/10/03 16:43:28 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dupl;
	int		i;

	i = 0;
	dupl = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dupl)
		return (NULL);
	while (s1[i] != '\0')
	{
		dupl[i] = s1[i];
		i ++;
	}
	dupl[i] = '\0';
	return (dupl);
}

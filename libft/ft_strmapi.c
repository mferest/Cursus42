/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:22:23 by manufern          #+#    #+#             */
/*   Updated: 2023/09/30 11:39:32 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		lengh;
	int		i;
	char	*new_str;

	i = 0;
	if (!s || !f)
		return (NULL);
	lengh = ft_strlen(s);
	new_str = (char *)malloc(lengh + 1);
	if (!new_str)
		return (NULL);
	while (i < lengh)
	{
		new_str[i] = f(i, s[i]);
		i ++;
	}
	new_str[lengh] = '\0';
	return (new_str);
}

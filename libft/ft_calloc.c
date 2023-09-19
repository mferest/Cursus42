/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:35:52 by manufern          #+#    #+#             */
/*   Updated: 2023/09/19 16:32:18 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*cero;
	int		i;

	i = 0;
	if (size == 0 || count == 0)
		return (NULL);
	cero = malloc(count * size);
	if (!cero)
		return (NULL);
	ft_memset(cero, 0, (count * size));
	return (cero);
}

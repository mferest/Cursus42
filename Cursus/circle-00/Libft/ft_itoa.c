/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:19:42 by manufern          #+#    #+#             */
/*   Updated: 2023/09/30 11:20:10 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digit(long n, long i)
{
	if (n == 0)
		return (1);
	if (n < 0)
		i ++;
	while (n != 0)
	{
		n = n / 10;
		i ++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*numb;
	long	i;
	long	j;

	j = n;
	i = ft_count_digit(n, 0);
	numb = (char *)malloc(sizeof(char) * (i + 1));
	if (!numb)
		return (NULL);
	if (n < 0)
		j = j * -1;
	numb[i] = '\0';
	while (i --)
	{
		numb[i] = j % 10 + 48;
		j = j / 10;
	}
	if (n < 0)
		numb[0] = '-';
	return (numb);
}

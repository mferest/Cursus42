/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:20:39 by manufern          #+#    #+#             */
/*   Updated: 2023/09/20 13:14:35 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sig;

	i = 0;
	num = 0;
	sig = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i ++;
	if (str[i] == '-')
		sig = 1;
	if (((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
		|| (str[i + 1] < '0' || str[i + 1] > '9'))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i ++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i ++;
	}
	if (sig == 1)
		return (num * -1);
	return (num);
}

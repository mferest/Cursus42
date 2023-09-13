/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:06:06 by manufern          #+#    #+#             */
/*   Updated: 2023/09/13 17:51:48 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*pone un caracter un un string tantas veces como quiero*/
void	*ft_memset(void *b, int c, size_t len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i ++;
	}
	return (b);
}

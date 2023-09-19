/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:39:54 by manufern          #+#    #+#             */
/*   Updated: 2023/09/18 18:30:02 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*convirte una letra de minuscula a mallusculas y devuelve la mayuscula*/
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

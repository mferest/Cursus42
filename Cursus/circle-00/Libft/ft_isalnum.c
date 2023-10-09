/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:58:52 by manufern          #+#    #+#             */
/*   Updated: 2023/09/20 13:00:03 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Esta funcion devuelve un 8 si es un numero o una letra
se es otra cosa devuelve un 0*/
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (8);
	else
		return (0);
}
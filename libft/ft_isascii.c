/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:25:40 by manufern          #+#    #+#             */
/*   Updated: 2023/09/12 17:28:18 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* esta funcion devuelve un 1 si es caracter asccii
devuelve un 0 si no es un caracter ascii*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

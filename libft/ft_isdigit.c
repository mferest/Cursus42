/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:49:05 by manufern          #+#    #+#             */
/*   Updated: 2023/09/18 18:26:32 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Esta funcion comprueba si lo que introducimos es un digito entre el 0 y el 9 
y si no es un digito entre essos numeros devulve un 0 
y si es un numero entre esos digitos devuelve 2048*/
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	else
		return (0);
}

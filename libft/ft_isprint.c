/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:33:25 by manufern          #+#    #+#             */
/*   Updated: 2023/09/13 18:17:11 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Si el caracter printeable devuelve 16384
si el caracter no es printeable devuelve 0 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	else
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:39:54 by manufern          #+#    #+#             */
/*   Updated: 2023/09/14 18:56:10 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*convirte una letra de minuscula a mallusculas y devuelve la mayuscula*/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:49:29 by manufern          #+#    #+#             */
/*   Updated: 2023/09/14 18:55:17 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* comvierte de mallusculas a minusculas y devuelve l convertido */
int	ft_tolower(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c + 32;
	return (c);
}

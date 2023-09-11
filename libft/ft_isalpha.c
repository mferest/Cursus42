/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:24:58 by manufern          #+#    #+#             */
/*   Updated: 2023/09/11 19:49:46 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha (int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return(1);
	else
		return(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:04:41 by manufern          #+#    #+#             */
/*   Updated: 2023/09/30 14:20:40 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 1;
	if (lst == NULL)
		return (0);
	temp = lst;
	while (temp->next != (void *)0)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

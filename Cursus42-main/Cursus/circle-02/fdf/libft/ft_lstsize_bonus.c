/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:04:41 by manufern          #+#    #+#             */
/*   Updated: 2023/10/05 16:59:13 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count_nodes;

	count_nodes = 0;
	while (lst != NULL)
	{
		count_nodes ++;
		lst = lst->next;
	}
	return (count_nodes);
}

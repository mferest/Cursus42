/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:04:40 by manufern          #+#    #+#             */
/*   Updated: 2023/10/05 16:50:25 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp_free;

	tmp = *lst;
	tmp_free = *lst;
	while (tmp != NULL)
	{	
		tmp = tmp->next;
		ft_lstdelone(tmp_free, del);
		tmp_free = tmp;
	}
	*lst = NULL;
}

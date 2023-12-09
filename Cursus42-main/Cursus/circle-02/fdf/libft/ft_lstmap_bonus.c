/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:07:42 by manufern          #+#    #+#             */
/*   Updated: 2023/10/02 16:09:17 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*lst_new;

	lst_new = NULL;
	new_node = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new_node = ft_lstnew((lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&lst_new, del);
			return (NULL);
		}
		new_node->content = f(lst->content);
		ft_lstadd_back(&lst_new, new_node);
		lst = lst->next;
	}
	return (lst_new);
}

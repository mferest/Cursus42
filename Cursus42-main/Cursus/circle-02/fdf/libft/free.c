/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:32:01 by manufern          #+#    #+#             */
/*   Updated: 2023/12/14 16:10:25 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

void ft_free_s_map(t_map **map)
{
    t_map    *aux;
    t_map    *dulp;
    
    printf("luverando");
    if (map == NULL)
    {
        printf("NULL");
       return; 
    }
        
    dulp = *map;
    while(dulp)
    {
        printf("a\n");
        aux = dulp->next;
        free(dulp);
        dulp = aux;
    }
    *map = NULL;
}


/* void ft_lstadd_back_map(t_map **lst, t_map *new) {
    t_map *tmp;
    if (*lst == NULL) {
        *lst = new;
    } else {
        tmp = *lst; 
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
} */
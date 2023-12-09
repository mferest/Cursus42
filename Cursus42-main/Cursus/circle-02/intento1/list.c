/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:44:34 by manufern          #+#    #+#             */
/*   Updated: 2023/12/09 19:00:57 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_map
{
  int *x;
  int *y;
  int *color;
  int *alt;
  struct s_map *up;
  struct s_map *down;
  struct s_map *right;
  struct s_map *left;
  struct s_map *next;
} t_map;

t_map *new_map_node(int *x, int *y, int *color, int *num)
{
  t_map *new_node = malloc(sizeof(t_map));

  if (new_node == NULL)
  {
    return NULL;
  }

  new_node->x = x;
  new_node->y = y;
  new_node->color = color;
  new_node->alt = num;
  new_node->up = NULL;
  new_node->down = NULL;
  new_node->right = NULL;
  new_node->left = NULL;
  new_node->next = NULL;

  return new_node;
}

void ft_lstadd_back(t_map **lst, t_map *new)
{
  t_map *tmp = *lst;

  if (*lst == NULL)
  {
    *lst = new;
  }
  else
  {
    while (tmp->next != NULL)
    {
      tmp = tmp->next;
    }
    if (new != NULL)
    {
      new = (t_map *)malloc(sizeof(t_map));
      if (new == NULL)
      {
        return ;
      }
      tmp->next = new;
    }
  }
}

void create_list(int x, int y, int num, char color)
{
  t_map *new_node ;
  t_map *map;
  
  map = NULL;
 new_node = new_map_node(x, y, color, num);
}

int main()
{
  // Create a new node
  t_map *lst;
  
  lst = NULL;
  int *x = malloc(sizeof(int));
  *x = 1;
  int *y = malloc(sizeof(int));
  *y = 2;
  int *color = malloc(sizeof(int));
  *color = 3;
  int *alt = malloc(sizeof(int));
  *alt = 4;
  t_map *new_node = new_map_node(x, y, color, alt);
  ft_lstadd_back(&lst, new_node);
  t_map *current = lst;
  while (current != NULL)
  {
    printf("x: %d\n", *current->x);
    printf("y: %d\n", *current->y);
    printf("color: %d\n", *current->color);
    printf("alt: %d\n", *current->alt);
    current = current->next;
  }
  return 0;
}

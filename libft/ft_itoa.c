/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:19:42 by manufern          #+#    #+#             */
/*   Updated: 2023/09/28 19:56:06 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_count_digit(int n, int i)
{
  if (n == 0)
    return (1);
  if (n < 0)
    i ++;
  while (n != 0)
  {
    n = n / 10;
    i ++;
  }

  return(i);
}
char *ft_itoa(int n)
{
  char *numb;

  numb = (char *)malloc(sizeof(char) * (ft_count_digit(n, 0) + 1));
  return;
}

int main()
{
    ft_itoa(0);
    return (0);
}

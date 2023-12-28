/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:01:57 by manufern          #+#    #+#             */
/*   Updated: 2023/12/28 14:40:50 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi_hexa(char *str)
{
    int nbr = 0;
    char todecimal;
    
    if (*str == '0')
    {
        str++;
    }
    if (*str == 'x')
    {
        str++;
    }
    while (*str)
    {
        todecimal = ft_toupper(*str);
        if (ft_isdigit(todecimal))
        {
            nbr = nbr * 16 + (todecimal - '0');
        } else if (ft_isalpha(todecimal))
        {
            nbr = nbr * 16 + (todecimal - 'A' + 10);
        }
        str++;
    }
    return nbr;
}
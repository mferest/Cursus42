/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:01:57 by manufern          #+#    #+#             */
/*   Updated: 2023/12/27 12:40:11 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi_hexa(char *str)
{
    int nbr = 0;
    char todecimal;
    // printf("Color char: %s\n", str);
    
    if (*str == '0')
    {
        str++;
    }
    if (*str == 'x')
    {
        str++;
    }
    // printf("%s\n", str);
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
    printf("metiendo en lista\n");
    return nbr;
}
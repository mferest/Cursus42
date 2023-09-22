/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:46:54 by manufern          #+#    #+#             */
/*   Updated: 2023/09/21 19:56:03 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* encuentra la ultima ocurriencia del carracterque queremos buscar*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		found;
	char		*end;

	end = (char *)s;
	found = (char )c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (end[i] == found)
			return (end + i);
		i --;
	}
	if (end[i] == found)
		return (end);
	return (NULL);
}

/*int main() {
    const char *str = "Hello, World!";
    int target_char = '\0';

    char *result = ft_strrchr(str, target_char);

    if (result) {
        printf("Última ocurrencia de 
	'\\0' en '%s' encontrada en la posición 
	%ld\n", str, result - str);
    } else {
        printf("'\\0' no se encontró en '%s'\n", str);
    }

    return 0;
}*/

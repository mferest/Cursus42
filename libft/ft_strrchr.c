/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:46:54 by manufern          #+#    #+#             */
/*   Updated: 2023/09/20 13:39:51 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* encuentra la ultima ocurriencia del carracterque queremos buscar*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_ocurrence;

	last_ocurrence = NULL;
	if (c == '\0')
	{
		while (*s != '\0')
			s++;
		return ((char *)s);
	}
	while (*s != '\0')
	{
		if (*s == (const char)c)
			last_ocurrence = s;
		s ++;
	}
	return ((char *)last_ocurrence);
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

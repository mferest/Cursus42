/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:46:54 by manufern          #+#    #+#             */
/*   Updated: 2023/09/19 19:04:40 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* encuentra la ultima ocurriencia del carracterque queremos buscar*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	last_ocurrence;

	last_ocurrence = -1;
	i = 0;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (const char)c)
			last_ocurrence = i;
		i++;
	}
	if (last_ocurrence != -1)
		return ((char *)&s[last_ocurrence]);
	return (NULL);
}
/*
int main() {
    const char *cadena = "Hola, mundo!";
    int caracter_buscado = 'o';

    char *resultado = ft_strrchr(cadena, caracter_buscado);

    if (resultado != NULL) {
        printf("La última ocurrencia de '%c' está en 
	la posición %ld.\n", caracter_buscado, resultado - cadena);
    } else {
        printf("El carácter '%c' no se encontró en i
	la cadena.\n", caracter_buscado);
    }

    return 0;
}*/

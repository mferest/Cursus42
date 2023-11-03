/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:52:33 by manufern          #+#    #+#             */
/*   Updated: 2023/11/03 20:38:45 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

int ft_is_format(char c)
{
    if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	ft_flag(va_list args, char c, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), 1);
 	/* else if (c == 's')
		
	else if (c == 'p')
		
	else if (c == 'd' || c == 'i')
		
	else if (c == 'u')
		
	else if (c == 'x' || c == 'X') */
		
	else if (c == '%')
		ft_putchar('%', 1);
}

int ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);

    
	while (str[i])
	{
		if (str[i] == '%' && ft_is_format(str[i + 1]))
		{
			ft_flag(args, str[i + 1], &len);
			i++;
		}
		else if (str[i] != '%')
		{
			ft_putchar(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

int main()
{
    ft_printf("%");
    /* ft_prinntf("hola que tal");
    ft_printf("printf original:\n");
    ft_printf("c: %c\n", 'a');
    ft_printf("s: %s\n", s);
    ft_printf("p: %p\n", p);
    ft_printf("d: %d\n", a);
    ft_printf("i: %i\n", a);
    ft_printf("u: %u\n", a); */
    /* ft_printf("x: %x\n", 50);
    ft_printf("X: %X\n", 50); */
}

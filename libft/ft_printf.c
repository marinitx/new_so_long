/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:09:23 by mhiguera          #+#    #+#             */
/*   Updated: 2023/07/04 17:04:37 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_format(va_list objects, char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length = length + ft_printchar(va_arg(objects, int));
	if (format == 's')
		length = length + ft_printstr(va_arg(objects, char *));
	if (format == 'p')
		length = length + ft_printpointer(va_arg(objects, unsigned long));
	if ((format == 'd') || (format == 'i'))
		length = length + ft_printnbr(va_arg(objects, int));
	if (format == 'u')
		length = length + ft_printunsigned(va_arg(objects, unsigned int));
	if (format == 'x')
		length = length + ft_printhexalow(va_arg(objects, unsigned int));
	if (format == 'X')
		length = length + ft_printhexacap(va_arg(objects, unsigned int));
	if (format == '%')
		length = length + ft_printpercent();
	return (length);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		length;
	va_list	objects;

	i = 0;
	length = 0;
	va_start(objects, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length = length + ft_format(objects, str[i + 1]);
			i++;
		}
		else
			length = length + ft_printchar(str[i]);
		i++;
	}
	va_end(objects);
	return (length);
}
/*
int main()
{
	int n = 593;
	printf("%d\n", ft_printf("%p", &n));
	ft_printf("%p", &n);
	printf("\n%p", &n);
	return(0);
}
*/

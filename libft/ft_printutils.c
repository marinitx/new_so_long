/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:27:13 by mhiguera          #+#    #+#             */
/*   Updated: 2023/12/09 14:33:19 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

long	ft_pointertohexa(unsigned long num)
{
	int		len;
	char	*str;

	str = "0123456789abcdef";
	len = 0;
	if (num >= 16)
		len = len + ft_pointertohexa(num / 16);
	len = len + write(1, str + (num % 16), 1);
	return (len);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printpointer(unsigned long ptr)
{
	int	len;

	len = 0;
	ft_printchar('0');
	ft_printchar('x');
	len = ft_pointertohexa(ptr) + 2;
	return (len);
}

int	ft_printnbr(int num)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		if (num == -2147483648)
		{
			i = i + write (1, "-2", 2);
			num = 147483648;
		}
		else
		{
			ft_printchar('-');
			num = num * -1;
			i++;
		}
	}
	if (num > 9)
		i = i + ft_printnbr(num / 10);
	i = i + ft_printchar((num % 10) + '0');
	return (i);
}

int	ft_printpercent(void)
{
	write (1, "%", 1);
	return (1);
}

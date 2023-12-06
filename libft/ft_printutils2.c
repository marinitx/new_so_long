/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printutils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:29:38 by mhiguera          #+#    #+#             */
/*   Updated: 2023/07/04 17:32:03 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_printunsigned(unsigned int u)
{
	int	i;

	i = 0;
	if (u > 9)
		i = i + ft_printunsigned(u / 10);
	i = i + ft_printchar((u % 10) + '0');
	return (i);
}

int	ft_printhexalow(unsigned int num)
{
	int		len;
	char	*strlow;

	strlow = "0123456789abcdef";
	len = 0;
	if (num >= 16)
		len = len + ft_printhexalow(num / 16);
	len = len + write(1, strlow + (num % 16), 1);
	return (len);
}

int	ft_printhexacap(unsigned int num)
{
	int		len;
	char	*strcap;

	len = 0;
	strcap = "0123456789ABCDEF";
	if (num >= 16)
		len = len + ft_printhexacap(num / 16);
	len = len + write(1, strcap + (num % 16), 1);
	return (len);
}

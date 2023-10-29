/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:08:52 by mhiguera          #+#    #+#             */
/*   Updated: 2023/02/27 18:09:42 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	if (num > 9)
	{
		ft_putnbr_fd((num / 10), fd);
		ft_putchar_fd(((num % 10) + '0'), fd);
	}
	else
		ft_putchar_fd(num + '0', fd);
}

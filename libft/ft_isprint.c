/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:37:42 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/20 17:17:16 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int a)
{
	if (a > 31 && a <= 126)
		return (1);
	else
		return (0);
}
/*int main(void)
{
	printf("%d", ft_isprint(123));
	printf("%c%d", '\n', isprint(123));
	return (0);
}*/
/*
 * Si es un caracter imprimible de ASCII retorna 1, sino retorna 0.
*/

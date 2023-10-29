/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:30:28 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/20 17:16:34 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int a)
{
	if (a <= 127 && a >= 0)
		return (1);
	else
		return (0);
}
/*int main(void)
{
	printf("%d", ft_isascii(21));
	printf("%c%d", '\n', isascii(21));
	return (0);
}*/
/*
 * Si es un caracter que puede ser representado como un caracter válido en
 * ASCII, entonces retorna 1, sino retorna 0.
*/

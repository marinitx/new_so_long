/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:18:31 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/20 17:15:11 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int a)
{
	if ((a > 64 && a < 91) || (a > 96 && a < 123) || (a > 47 && a < 58))
		return (1);
	else
		return (0);
}
/*int main(void)
{
	printf("%d", ft_isalnum(125));
	printf("%c%d", '\n', isalnum(125));
	return (0);
}*/
/*
 * Si es un número o una letra mayúscula o minúscula retorna 1, sino, retorna 0
*/

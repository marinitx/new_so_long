/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:31:13 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/20 16:47:00 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int a)
{
	if ((a > 64 && a < 91) || (a > 96 && a < 123))
	{
		return (1);
	}
	else
		return (0);
}
/*int main(void)
{
	printf("%d", ft_isalpha(95));
	printf("%c%d", '\n', ft_isalpha(95));
	return 0;
}*/
/*
 * Si el valor que le he pasado es una letra mayúscula o minúscula que retorne
 * 1, sino, retorna 0.
*/

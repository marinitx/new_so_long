/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:10:42 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/20 17:12:37 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int a)
{
	if (a > 47 && a < 58)
		return (1);
	else
		return (0);
}
/*int main(void)
{
	printf("%d", ft_isdigit(51));
	printf("%c%d", '\n', isdigit(51));
	return (0);
}*/
/*
 * Si me pasan un número retorna 1 y sino retorna 0.
*/

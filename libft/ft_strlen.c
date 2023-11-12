/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:27:51 by mhiguera          #+#    #+#             */
/*   Updated: 2023/11/12 21:21:41 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*int main(void)
{
	char str[] = "manolo"; 

	printf("%lu", strlen(str));
	printf("%c%d", '\n', ft_strlen(str));
	return (0);
}*/
/*
 * Dado un string, iterando un while con un contador que se va sumando, 
 * retorna el valor del contador cuando se ha terminado el string.
*/

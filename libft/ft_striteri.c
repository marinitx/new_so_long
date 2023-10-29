/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:12:57 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/21 19:47:01 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
	return ;
}
/*
 * A cada carácter de la string ’s’, aplica la función ’f’ dando como
 * parámetros el índice de cada carácter dentro de ’s’ y la dirección del 
 * propio carácter, que podrá modificarse si es necesario.
*/

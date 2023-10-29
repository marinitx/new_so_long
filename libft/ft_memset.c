/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:50:25 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/20 17:24:05 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
/*
 * Escribe tantos bytes de c como len me hayan pasado en el string b.
 * A través de un contador que se irá sumando mientras que sea inferior a la
 * longitud len, voy cambiando cada valor del string original por lo que me
 * hayan pasado como c.
*/

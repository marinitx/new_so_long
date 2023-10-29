/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:04:50 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/20 18:47:03 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*cast;

	i = 0;
	cast = (char *)s;
	while (i < n)
	{
		if (cast[i] == (char)c)
			return (cast + i);
		i++;
	}
	return (0);
}
/*
 * Primero casteo s en char * y luego voy comparando hasta n si coinciden los
 * caracteres de s con el c que me pasen. Si coincide, que me retorne la
 * posición en el string donde han coincidido por primera vez. Si no coincide
 * nada, devuelve 0.
*/

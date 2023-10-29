/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:31:22 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/21 18:43:18 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ptr = ft_calloc(sizeof (char), len + 1);
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[i + start];
		i++;
	}
	return (ptr);
}
/*
s: La string desde la que crear la substring.
start: El índice del caracter en ’s’ desde el que empezar la substring.
len: La longitud máxima de la substring.
Reserva (con malloc(3)) y devuelve una substring de la string ’s’.
La substring empieza desde el índice ’start’ y tiene una longitud máxima ’len’.

Si la posición del start es mayor que lo que mide el propio string, que
directamente devuelva un string nuevo creado que esté vacío. Si la longitud
de la substring que me piden es mayor que lo que mide el string desde la 
posición de start hasta el final del string, entonces que la longitud ahora sea
justo desde start hasta el final del string.
*/

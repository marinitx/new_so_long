/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:27:53 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/21 19:45:45 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = ft_calloc(sizeof (char), ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = (f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
 * A cada carácter de la string ’s’, aplica la función ’f’ dando como 
 * parámetros el índice de cada carácter dentro de ’s’ y el propio carácter.
 * Genera una nueva string con el resultado del uso sucesivo de ’f’.
 *
 * Primero crea el string, y a cada caracter le aplica la función. Finalmente
 * se termina el string en nulo.
*/

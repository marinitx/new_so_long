/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:27:41 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/20 18:03:21 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
/*
int main()
{
	printf("%s", strchr("manolo", 's'));
	printf("%c%s\n", '\n', ft_strchr("manolo", 's'));
	return 0;
}*/
/*
 * Sitúa la primera ocurrencia de c convertido a char en el string de s,
 * incluyendo el valor nulo del final. Recorriendo el string s, si alguno de 
 * sus caracteres coincide con c, retorna un puntero a la posición donde lo ha
 * encontrado por primera vez. Luego, cuando ya ha terminado el string, por si
 * acaso c es un nulo, lo vuelve a comprobar fuera del while.
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:25:05 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/20 18:10:38 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (((char *)s) + i);
		i--;
	}
	return (NULL);
}
/*int main()
{
	printf("%s%c", strrchr("manolo", 'n'), '\n');
	printf("%s", ft_strrchr("manolo", 'n'));
	return 0;
}*/
/*
 * Sitúa la última ocurrencia de c convertido a char en el string de s.
 * Recorriendo el string s, si alguno de sus caracteres coincide con c, retorna
 * un puntero a la posición donde lo ha encontrado por primera vez mirando al
 * final hacia atrás (el último). Al principio también comprobará el nulo.
*/

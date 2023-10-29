/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:28:57 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/20 17:32:25 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (size < 1)
		return (j);
	while ((src[i] != '\0') && (i < size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}
/*int main(void)
{
	char dest[] = "manolo";
	char src[] = "lolito";
	printf("%zu", ft_strlcpy(dest, src, 4));
}*/
/*
 * Dados dos strings, voy a copiar src en dest hasta la longitud size - 1,
 * y terminaré el resultado en NULL si size no es 0. Si size es 0, retorna un
 * strlen de src (es decir, la longitud del string de src).
*/

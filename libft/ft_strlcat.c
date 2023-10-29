/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:58:28 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/20 17:51:06 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(src);
	j = ft_strlen(dst);
	k = 0;
	if (dstsize <= j)
		return (dstsize + i);
	while ((src[k] != '\0') && (j + k < dstsize - 1))
	{
		dst[j + k] = src[k];
		k++;
	}
	if (j + k == dstsize && j < dstsize)
		dst[j + k - 1] = '\0';
	else
		dst[j + k] = '\0';
	return (j + i);
}
/*
int main()
{
//	char *str[90] = "manolo";
	char *dest;
//	str = "manolo";
	dest[10] = 'a;
    printf("%zu", ft_strlcat(dest, "lorem ipsum dolor sit amet", 0));
    write(1, "\n", 1);
    write(1, dest, 15);
	return 0;
}*/
/*
 * Strlcat añade el string src al final del string dst a lo sumo dstsize
 * - strlen(dst) - 1, y luego va a terminar en NULL a menos que dstsize sea 0 o
 * que el string original dst sea mayor a dstsize.
 * i va a ser la longitud de src y j la longitud de dst. Si me pasan una
 * longitud menor (o igual) que la longitud total del string dst, entonces
 * me va a retornar directamente la longitud que me han pasado + la longitud
 * del string src normal (directamente pone el src al final de dst donde
 * termina dstsize). En el caso opuesto, crearé un nuevo contador k que se irá
 * sumando para recorrer src y poder añadirlo al final de dst (dst de j + k).
 * Luego lo acabo en nulo y retorno el valor de la suma entre lo que mide src 
 * y dst.
*/

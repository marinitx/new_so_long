/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:20:21 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/20 17:29:50 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	if (src < dest)
		while (len-- > 0)
			((char *)dest)[len] = ((char *)src)[len];
	else
	{
		while (i < len)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
int main()
{
//	char src[] = "lorem ipsum dolor sit amet";
//	char *dest;
//	dest = src + 1;
	printf("%s", ft_memmove("abcde", "abc", 3));
//	if (dest != ft_memmove(dest, src, 8))
//		write(1, "dest's adress was not returned\n", 31);
//	write(1, dest, 22);
	return 0;
}*/
/*
 * Memmove va a copiar al igual que memcpy cada caracter del string src en el
 * string dest a través de un contador que será igual para ambos strings, pero
 * como diferencia, memmove si soporta el overlap, es decir, como un tampón de
 * clonar en photoshop.
*/

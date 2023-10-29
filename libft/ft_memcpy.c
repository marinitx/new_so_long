/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:45:58 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/20 17:27:18 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
/*
 * A través de un bucle con un contador que se irá sumando hasta la longitud de
 * n, iré poniendo cada caracter del string src como caracter del string dest
 * en la misma posición.
 * */

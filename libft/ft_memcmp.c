/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:27:21 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/01 20:51:52 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cast1;
	unsigned char	*cast2;

	i = 0;
	cast1 = (unsigned char *)s1;
	cast2 = (unsigned char *)s2;
	while (i < n)
	{
		if (cast1[i] != cast2[i])
			return (cast1[i] - cast2[i]);
		i++;
	}
	return (0);
}

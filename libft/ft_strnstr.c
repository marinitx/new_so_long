/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:45:32 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/10 18:57:40 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (n[i] == '\0')
		return ((char *)h);
	while (h[i] != '\0' && i <= len)
	{
		j = 0;
		while (h[i] && n[j] == h[i + j] && i + j < len)
		{
			j++;
			if (n[j] == '\0')
				return ((char *)h + i);
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	char *s;
	char *p;
	s = "lorem ipsum dolor sit amet";
	p = "ipsum";
	printf("%s", ft_strnstr(s, p, 30));
	printf("%c%s", '\n', strnstr(s, p, 30));
	return 0;
}
*/

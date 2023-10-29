/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:11:22 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/20 19:00:22 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = 0;
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1[j] != '\0')
	{
		str[j] = s1[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
/*
 * Creo un nuevo string reservando memoria con calloc, y con un bucle voy a 
 * copiarle los caracteres de s1 en mi nuevo strng, finalizandolo con un NULL.
*/

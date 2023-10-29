/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:31:47 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/21 18:56:22 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		z;
	char	*s3;

	i = 0;
	j = 0;
	z = ft_strlen(s1) + ft_strlen(s2);
	s3 = ft_calloc(sizeof (char), z + 1);
	if (!s3)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	return (s3);
}
/*
int main()
{
	printf("%s", ft_strjoin("manolo", "pepe"));
	return 0;
}
*/
/*
Reserva (con malloc(3)) y devuelve una nueva string, formada por la
concatenación de ’s1’ y ’s2’.

Entonces creo un nuevo string y voy copiándole a mi nuevo string el string s1.
Luego, s3 va a seguir avanzando y se va a ir copiando s2 desde el inicio.
*/

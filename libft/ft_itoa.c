/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:42:11 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/21 19:39:02 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 1;
	if (n == -2147483647 - 1)
		return (11);
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_to_positive(int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

char	*ft_itoa(int n)
{
	int			i;
	char		*str;
	long int	n2;

	n2 = ft_to_positive(n);
	str = ft_calloc(sizeof (char), ft_intlen(n) + 1);
	if (!str)
		return (NULL);
	if (n == -2147483647 - 1)
		n2 = 2147483648;
	if (n == 0)
		str[0] = '0';
	i = ft_intlen(n) - 1;
	while (i >= 0)
	{
		str[i] = n2 % 10 + 48;
		i--;
		n2 = n2 / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
/*
int main()
{
	int n = 0;
	printf("%s", ft_itoa(n));
	return 0;
}
*/
/*
 * La primera función me dice cuánto mide el int que me han pasado. Para eso, 
 * primero mira si es un número negativo o positivo, si es negativo que lo
 * convierta en positivo y que avance el contador de la i. Mientras que sea un
 * número de dos cifras o más, que lo divida entre 10 hasta que sea de 1 cifra.
 * Le va a añadir también al contador que es lo que voy a retornar.
 *
 * La segunda función convierte el número en positivo.
 *
 * La función principal convierte un int que me han pasado a un char.
 * Para eso, primero comprueba su signo llamando a la segunda función. Luego
 * crea el string del tamaño que me ha devuelto la primera función.
 * Después, comprueba casos raros y luego, con el contador al máximo de tamaño
 * del string, que vaya retrocediendo haciendo el módulo de cada cifra entre 10
 * y sumándole 48 (ascii), y dividiendo entre 10 para retroceder de número.
 * Finalmente, si era en un principio un número negativo, ahora en la posición
 * 0 añado un -.
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:52:49 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/21 19:19:06 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != '\0')
	{
		if ((i == 0) || (s[i] != c && s[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

static void	ft_free_array(char **str, int word)
{
	while (word > 0)
	{
		free(str[word]);
		word--;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		word;
	char	**str;

	i = 0;
	word = 0;
	if (!s)
		return (NULL);
	str = ft_calloc(sizeof (char *), (ft_count_words(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0' && word < ft_count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		str[word++] = ft_substr(s, j, (i - j));
	}
	if (!str)
		ft_free_array(str, ft_count_words(s, c));
	return (str);
}
/*
int main()
{
	int i;
	char **result;

	i = 0;
	result = ft_split("", euismod non, mi.", 'z');

	while (result[i])
	{	
		printf("%s%c", result[i], '\n');
		i++;
	}
	
	
		printf("%s%c", result[i], '\n');
	//	printf("%s%c", result[1], '\n');
//	printf("%d", ft_count_words("   split       this for   me  !     ", ' '));
	return 0;
}
*/
/*
 * La primera función cuenta las palabras. Se le pasa el string de palabras,
 * y el separador (generalmente un espacio). Si los caracteres del string 
 * coinciden con el separador antes de que haya palabras, que siga avanzando,
 * cuando encuentre la primera letra, si el caracter no es un separador y el 
 * caracter anterior si lo era, significa que estamos ante una nueva palabra.
 *
 * La segunda función libera el array, se utilizará solo cuando falle.
 *
 * La función principal divide el array en mini-strings separadas por el
 * separador que le pasemos (c). Primero crea el nuevo string, que tendrá el
 * tamaño del número de palabras que haya + el '\0'.
 * Mientras que las palabras no se hayan terminado, si encuentro separadores
 * que siga avanzando y que situe el nuevo inicio con j = i donde haya letra.
 * Luego irá avanzando hasta que ya no haya letra, y eso será la primera
 * palabra, que con substr me va a crear un substring con ese tamaño. Esto lo
 * va a hacer todo el rato con todas las palabras porque está metido en un 
 * bucle. Luego liberará en caso de que falle y retornará el string resultante.
*/

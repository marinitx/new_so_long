/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:23:58 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/20 18:57:19 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] == '\t') || (str[i] == '\r')
		|| (str[i] == '\v') || (str[i] == '\n') || (str[i] == '\f'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] > 47 && str[i] < 58)
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
/*
int main()
{
	char *num = "\016 15";
	printf("%d", atoi(num));
	printf("\n%d", ft_atoi(num));
	return 0;
}
*/
/*
 * Atoi convierte un string de números en un int. Si hay espacios, o símbolos
 * de isspace, que siga avanzando con el contador. Si detecta un - justo antes
 * del número, significa que es negativo y por tanto sign va a ser -1.
 * Sin embargo, si hay varios signos en el string, que los avance.
 * Luego comprueba que realmente se trata de un número y para convertirlo a int
 * solo tiene que multiplicarlo por 10 y restarle si valor en ascii. Finalmente
 * retorna el valor de num multiplicado por 1 si es positivo o -1 si es
 * negativo.
*/

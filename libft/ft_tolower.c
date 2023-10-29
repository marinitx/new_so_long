/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:06:41 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/20 17:54:18 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int ch)
{
	if ((ch <= 'Z') && (ch >= 'A'))
		ch = ch + 32;
	return (ch);
}
/*
 * Dada una letra mayúscula, retorna la misma letra minúscula por su valor
 * ASCII.
*/

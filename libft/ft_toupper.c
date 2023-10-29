/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:06:54 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/20 17:52:29 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int ch)
{
	if ((ch >= 'a') && (ch <= 'z'))
	{
		ch = ch - 32;
	}
	return (ch);
}
/*
 * Dada una letra minúscula, retorna una letra mayúscula según los valores de
 * ASCII.
*/

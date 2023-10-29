/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:37:43 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/19 19:31:38 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != '\0')
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
 * Creo un "strlen" de nodos. Para eso, con un contador que se va sumando en 
 * el while, cuento la cantidad de nodos. La lista irá avanzando con el puntero
 * a "next" que se quedará guardada como nueva posición en la lista.
*/

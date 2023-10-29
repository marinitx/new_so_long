/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:01:36 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/19 19:42:24 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if ((!del) || (!lst))
		return ;
	while (*lst != '\0')
	{
		ft_lstdelone(*lst, del);
		*lst = (*lst)->next;
	}
	(*lst) = NULL;
}
/*
 * Primero compruebo los valores que me pasan, y luego mientras la lista no se
 * acabe, que vaya liberando cada nodo. Para pasar al siguiente nodo me situaré
 * en la posición de next. Al final el puntero de la lista debe ser NULL.
*/

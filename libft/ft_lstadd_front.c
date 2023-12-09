/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:22:57 by mhiguera          #+#    #+#             */
/*   Updated: 2023/12/09 14:22:47 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst != '\0' && new != '\0')
		new->next = *lst;
	*lst = new;
}
/* Añade el nodo "new" al principio de la lista 'lst'.
lst: la dirección de un puntero al primer nodo de una lista.
new: un puntero al nodo que añadir al principio de la lista.

Accede a new y le dice que el puntero de next apunte al inicio de la lista.
En *lst = new guarda la posición de new como nueva dirección del primer nodo
que ahora es new.
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:25:18 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/19 19:34:55 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while ((lst != '\0') && (lst->next != '\0'))
		lst = lst->next;
	return (lst);
}
/*
 * Mientras que no se haya acabado la lista y al menos el siguiente nodo exista
 * mi nueva posición se establecerá en el siguiente nodo. Es decir, si estoy
 * en una lista de 5 nodos, me pararé cuando esté en el nodo 4 (aún hay otro 
 * nodo más) y mi nueva posición será el siguiente nodo (que será el último).
*/

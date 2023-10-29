/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:29:27 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/19 19:58:37 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*lst_start;

	if ((!lst) || (!del) || (!f))
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (NULL);
	lst_start = new_lst;
	lst = lst->next;
	while (lst != '\0')
	{
		new_lst->next = ft_lstnew(f(lst->content));
		if (!new_lst)
		{
			ft_lstclear(&lst_start, del);
			return (0);
		}
		new_lst = new_lst->next;
		lst = lst->next;
	}
	new_lst->next = NULL;
	return (lst_start);
}
/*
 *Primero compruebo que los valores que me hayan pasado sean válidos.
 Luego creo el primer nodo al que le voy a meter la función f, ese primer nodo
 lo voy a guardar en una nueva variable que sera el inicio de mi lista.
 Avanzo al siguiente nodo de la lista original, y hasta que esa lista no se
 termine, voy a ir creando nuevos nodos con el puntero next para que vayan
 a continuación uno de otro cada vez que se itera el while, así, iré avanzando
 en ambas listas, en la original y en la mia creada. Cuando la lista original
 haya terminado, terminaré mi lista apuntando el puntero de next a NULL.
 Devuelvo el valor guardado antes porque mi lista ya ha avanzado hasta la
 posición final y yo quiero que la lea desde el primer nodo.
*/

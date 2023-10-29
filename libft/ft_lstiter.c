/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:20:46 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/19 19:43:52 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != '\0')
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
 * Mientras que no se haya acabado la lista, quiero que vaya aplicando la
 * función f al content de cada nodo. Avanzaré de nodo situándome en la
 * posición next.
*/

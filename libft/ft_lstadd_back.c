/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:34:58 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/17 17:00:36 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (*lst == NULL)
		*lst = new;
	else
	{
		node = ft_lstlast(*(lst));
		node->next = new;
	}
}
/*
Si la lista está vacía significa que la lista ya es el final de la lista.
Si no, quiero que me mire cuál es el último nodo de la lista con ft_lstlast y
que lo guarde en node. El puntero next lo llevaré a new para que así new sea el
último.
*/

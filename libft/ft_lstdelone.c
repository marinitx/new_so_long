/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:38:45 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/19 19:37:31 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if ((!del) || (!lst))
		return ;
	del(lst->content);
	free(lst);
}
/*
 * Primero compruebo los valores que me pasan, y luego a content le aplico la
 * función de "del" para liberar su memoria. Next pide no liberarlo.
 * Finalmente libero el nodo entero.
*/

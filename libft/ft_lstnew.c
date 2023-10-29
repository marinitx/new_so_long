/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:57:56 by mhiguera          #+#    #+#             */
/*   Updated: 2023/03/19 19:29:19 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
int main()
{
	t_list *elem;

	char	str [] = "lorem ipsum dolor sit";

		if (!(elem = ft_lstnew(str)))
				printf("%s","NULL");
		else
		{
			if (!(elem->content))
				printf("%s", "NULL");
			else
			{
				printf("%s", elem->content);
			}
			if (!(elem->next))
			{
				write(1, "\n", 1);
				printf("%s","NULL");
			}
		}
	return (0);
}
*/
/*
 * Creo una nueva lista con malloc y compruebo, a content le meteré content,
 * y a next, NULL, porque termina.
*/

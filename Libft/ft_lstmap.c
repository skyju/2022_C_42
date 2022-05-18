/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:00:04 by mkwak             #+#    #+#             */
/*   Updated: 2022/04/27 12:58:04 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*prev;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	prev = NULL;
	while (lst)
	{	
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&prev, del);
			return (NULL);
		}
		ft_lstadd_back(&prev, new);
		new = new->next;
		lst = lst->next;
	}
	return (prev);
}

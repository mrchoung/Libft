/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeloneif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 18:19:17 by mfranc            #+#    #+#             */
/*   Updated: 2017/11/24 10:15:16 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone_if(t_ctl_list *ctl_list,
		int (*f)(t_list *elem, void *op), void *op)
{
	t_list	*node;

	node = ctl_list->head;
	while (node)
	{
		if (f(node, op))
			ft_lstdelone(ctl_list, &node);
		else
			node = node->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:35:00 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/21 11:17:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	reverse(t_list **begin_list, t_list **curr, t_list *prev)
{
	if (curr != NULL && *curr != NULL)
	{
		reverse(begin_list, &(*curr)->next, *curr);
		(*curr)->next = prev;
	}
}

t_list	*list_last(t_list *begin_list)
{
	if (begin_list != NULL)
	{
		while (begin_list->next != NULL)
			begin_list = begin_list->next;
	}
	return (begin_list);
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*last;

	if (begin_list != NULL)
	{
		last = list_last(*begin_list);
		reverse(begin_list, begin_list, NULL);
		*begin_list = last;
	}
}

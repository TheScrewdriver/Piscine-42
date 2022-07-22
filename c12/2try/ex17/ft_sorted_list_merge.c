/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:45:40 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/20 19:40:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list != NULL)
	{
		begin_list = begin_list->next;
		++count;
	}
	return (count);
}

void	list_sort(t_list **begin_list, int (*cmp)())
{
	const int	size = list_size(*begin_list);
	int			i;
	t_list		*curr;
	void		*tmp;

	curr = *begin_list;
	if (curr != NULL)
	{
		i = 0;
		while (i < size)
		{
			while (curr->next != NULL)
			{
				if (cmp(curr->data, (curr->next)->data) > 0)
				{
					tmp = curr->data;
					curr->data = (curr->next)->data;
					(curr->next)->data = tmp;
				}
				curr = curr->next;
			}
			curr = *begin_list;
			++i;
		}
	}
}

void	list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if (begin_list1 != NULL)
	{
		if (*begin_list1 != NULL)
			list_merge(&(*begin_list1)->next, begin_list2);
		else
			*begin_list1 = begin_list2;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	if (begin_list1 != NULL)
	{
		list_merge(begin_list1, begin_list2);
		list_sort(begin_list1, cmp);
	}
}

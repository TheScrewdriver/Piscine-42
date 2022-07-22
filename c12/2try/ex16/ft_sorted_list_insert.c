/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:50:15 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/20 22:39:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	list_push_back(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*curr;

	if (begin_list != NULL)
	{
		new = ft_create_elem(data);
		if (*begin_list != NULL)
		{
			curr = *begin_list;
			while (curr->next != NULL)
				curr = curr->next;
			curr->next = new;
		}
		else
			*begin_list = new;
	}
}

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

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	if (begin_list != NULL)
	{
		list_push_back(begin_list, data);
		list_sort(begin_list, cmp);
	}
}

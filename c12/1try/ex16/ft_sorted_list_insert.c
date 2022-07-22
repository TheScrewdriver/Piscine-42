/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:50:15 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/20 11:24:43 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*curr;

	new = ft_create_elem(data);
	if (begin_list != NULL)
	{
		curr = *begin_list;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new;
	}
}

int	ft_list_size(t_list *begin_list)
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

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	const int	size = ft_list_size(*begin_list);
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
	if (begin_list != NULL && *begin_list != NULL)
	{
		ft_list_push_back(begin_list, data);
		ft_list_sort(begin_list, cmp);
	}
}

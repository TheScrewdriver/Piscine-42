/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:05:47 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/20 11:22:37 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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

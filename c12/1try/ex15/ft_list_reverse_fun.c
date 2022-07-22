/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:18:00 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/20 09:47:28 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (begin_list != NULL && i < nbr)
	{
		begin_list = begin_list->next;
		++i;
	}
	return (begin_list);
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

void	ft_list_reverse_fun(t_list *begin_list)
{
	const int	size = ft_list_size(begin_list);
	int			i;
	void		*tmp;
	t_list		*curr;
	t_list		*last;

	i = 0;
	curr = begin_list;
	while (i < size - i - 1)
	{
		tmp = curr->data;
		last = ft_list_at(begin_list, size - 1 - i);
		curr->data = last->data;
		last->data = tmp;
		curr = curr->next;
		++i;
	}
}

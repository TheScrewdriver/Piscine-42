/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:40:40 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/20 12:20:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new;

	if (begin_list != NULL && *begin_list != NULL)
	{
		new = ft_create_elem(data);
		new->next = *begin_list;
		*begin_list = new;
	}
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*begin;

	begin = NULL;
	if (strs != NULL)
	{
		if (size > 0)
			begin = ft_create_elem(strs[0]);
		i = 1;
		while (i < size)
		{
			ft_list_push_front(&begin, strs[i]);
			++i;
		}
	}
	return (begin);
}

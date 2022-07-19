/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:30:11 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/19 17:13:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdio.h>

void	delete_node(t_list **begin_list, void (*free_fct)(void *))
{
	t_list	*tmp;

	tmp = *begin_list;
	if (tmp != NULL)
	{
		*begin_list = tmp->next;
		free_fct(tmp->data);
		free(tmp);
	}
}

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	while (begin_list != NULL)
	{
		if (cmp(begin_list->data, data_ref) == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
			void (*free_fct)(void *))
{
	t_list	*first;
	t_list	*curr;

	if (cmp((*begin_list)->data, data_ref) == 0)
		delete_node(begin_list, free_fct);
	first = *begin_list;
	curr = *begin_list;
	while (curr->next != NULL && ft_list_find(first, data_ref, cmp) != NULL)
	{
		if (cmp(curr->data, data_ref) == 0)
			delete_node(begin_list, free_fct);
		printf("----> %s \n", (char *)((*begin_list)->data));
		curr = curr->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:30:11 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/20 13:04:07 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	delete_node(t_list **begin_list, void (*free_fct)(void *))
{
	t_list	*tmp;

	tmp = *begin_list;
	*begin_list = (*begin_list)->next;
	free_fct(tmp->data);
	free(tmp);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
			void (*free_fct)(void *))
{
	if (begin_list != NULL && *begin_list != NULL)
	{
		if (cmp((*begin_list)->data, data_ref) == 0)
		{
			delete_node(begin_list, free_fct);
			ft_list_remove_if(begin_list, data_ref, cmp, free_fct);
		}
		else
			ft_list_remove_if(&((*begin_list)->next), data_ref, cmp, free_fct);
	}
}

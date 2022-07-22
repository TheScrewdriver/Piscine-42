/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:41:34 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/20 22:33:19 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:36:15 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/19 11:50:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)())
{
	if (begin_list != NULL)
	{
		if (cmp(begin_list->data, data_ref) == 0)
			(*f)(begin_list->data);
		ft_list_foreach_if(begin_list->next, f, data_ref, cmp);
	}
}

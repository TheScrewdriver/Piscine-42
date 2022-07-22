/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:25:37 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/19 19:59:12 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if (begin_list1 != NULL)
	{
		if (*begin_list1 != NULL)
			ft_list_merge(&(*begin_list1)->next, begin_list2);
		else
			*begin_list1 = begin_list2;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:35:00 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/20 18:41:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	reverse(t_list **begin_list, t_list *prev)
{
	if (begin_list != NULL && *begin_list != NULL)
	{
		reverse(&(*begin_list)->next, *begin_list);
		(*begin_list)->next = prev;
	}
}

void	ft_list_reverse(t_list **begin_list)
{
	reverse(begin_list, NULL);
}

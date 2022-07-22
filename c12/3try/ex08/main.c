/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:35:30 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/20 23:55:24 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new != NULL)
	{
		new->data = data;
		new->next = NULL;
	}
	return (new);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new;

	if (begin_list != NULL)
	{
		new = ft_create_elem(data);
		new->next = *begin_list;
		*begin_list = new;
	}
}

void	display_list(t_list *begin_list)
{
	if (begin_list != NULL)
	{
		display_list(begin_list->next);
		printf("%s\n", (char *)(begin_list->data));
	}
}

t_list	*ft_list_last(t_list *begin_list)
{
	if (begin_list != NULL)
	{
		while (begin_list->next != NULL)
			begin_list = begin_list->next;
	}
	return (begin_list);
}

void	display(void *data)
{
	printf("%s\n", (char *)(data));
}

int	main(void)
{
	t_list	*list;

	list = NULL;
	ft_list_push_front(&list, "Hello0");
	ft_list_push_front(&list, "Hello1");
	ft_list_push_front(&list, "Hello2");
	ft_list_foreach(list, &display);
	return (0);
}

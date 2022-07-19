/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:35:30 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/19 18:23:47 by rbroque          ###   ########.fr       */
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
		printf("%s", (char *)(begin_list->data));
		printf("\n");
		display_list(begin_list->next);
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

#include <stdlib.h>
#include <string.h>

void	free_fct(void *data)
{
	free(data);
}

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	if (begin_list != NULL)
	{
		ft_list_clear(begin_list->next, free_fct);
		free_fct(begin_list->data);
		free(begin_list);
	}
}

int	main(void)
{
	t_list	*list;
	char	*str0;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	str0 = strdup("Hello0");
	str1 = strdup("Hello1");
	str2 = strdup("Hello0");
	str3 = strdup("Hello0");
	str4 = strdup("Hello4");
	list = ft_create_elem(str4);
	ft_list_push_front(&list, str3);
	ft_list_push_front(&list, str2);
	ft_list_push_front(&list, str1);
	ft_list_push_front(&list, str0);
	display_list(list);
	ft_list_remove_if(&list, "Hello0", &strcmp, &free_fct);
	printf("\n\n");
	display_list(list);
	ft_list_clear(list, free_fct);
	return (0);
}

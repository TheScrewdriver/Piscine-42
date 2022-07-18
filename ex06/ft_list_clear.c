/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:30:32 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/18 22:40:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	if (begin_list->next != NULL)
}

////////////////////////////////////////////////////////////////////////////////

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

int	main(void)
{
	t_list	*list;

	list = ft_create_elem("hello");
	ft_list_push_front(&list, "ouaah");
	ft_list_clear(list, &free);
	return (0);
}

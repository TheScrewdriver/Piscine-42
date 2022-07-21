/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 22:12:15 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/21 22:41:56 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	t_btree	*new;

	if (root != NULL)
	{
		new = btree_create_node(item);
		if (*root == NULL)
			*root = new;
		else
		{
			if (cmpf((*root)->item, item) > 0)
				btree_insert_data(&(*root)->left, item, cmpf);
			else
				btree_insert_data(&(*root)->right, item, cmpf);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:25:29 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/21 22:42:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item);
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));

void	display_node(t_btree *node)
{
	printf("(addr = %p) data --> %s\nleft --> %p; right --> %p\n\n", node, (char *)(node->item), node->left, node->right);
}

void	display(void *data)
{
	printf("%s\n", (char *)data);
}

#include <string.h>
int	comp(void *a, void *b)
{
	return (strcmp((char *)a, (char *)b));
}


int	main(void)
{
	t_btree	*root;

	root = NULL;
	btree_insert_data(&root, "5", comp);
	btree_insert_data(&root, "4", comp);
	btree_insert_data(&root, "7", comp);
	btree_insert_data(&root, "8", comp);
	btree_insert_data(&root, "6", comp);
	btree_insert_data(&root, "5", comp);
	btree_insert_data(&root, "3", comp);
	btree_insert_data(&root, "1", comp);

//	display_node(root);
/*
	root->left = btree_create_node("B");
	root->right = btree_create_node("C");

	root->left->left = btree_create_node("D");
	root->left->right = btree_create_node("E");

	root->right->left = btree_create_node("F");
	root->right->right = btree_create_node("G");
*/
	display_node(root);
	printf("Prefix:\n");
	btree_apply_prefix(root, &display);
/*
	printf("Infix:\n");
	btree_apply_infix(root, &display);
	printf("Postfix:\n");
	btree_apply_suffix(root, &display);
	return (0);
*/
}

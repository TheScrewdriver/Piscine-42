/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbrisse <axbrisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:29:26 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/25 21:03:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_matrix(size_t **matrix, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		++i;
	}
	free(matrix);
}

void	free_lines(char **lines)
{
	size_t	i;

	if (lines != NULL)
	{
		i = 0;
		while (lines[i] != NULL)
		{
			free(lines[i]);
			++i;
		}
		free(lines);
	}
}

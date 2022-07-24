/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:27:42 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/24 11:27:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	free_strings(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		++i;
	}
	free(strs[i]);
	free(strs);
}

void	free_maps(t_map **maps)
{
	size_t	i;

	i = 0;
	while ((*maps)[i].value != NULL)
	{
		free((*maps)[i].value);
		++i;
	}
	free(*maps);
}

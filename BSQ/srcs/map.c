/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:44:02 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/26 13:52:19 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

size_t	**init_matrix(t_map map)
{
	size_t	**matrix;
	size_t	y;

	matrix = malloc(sizeof(size_t *) * map.height);
	if (matrix == NULL)
		return (NULL);
	y = 0;
	while (y < map.height)
	{
		matrix[y] = malloc(sizeof(size_t) * map.width);
		if (matrix[y] == NULL)
		{
			free_matrix(matrix, y);
			return (NULL);
		}
		y++;
	}
	return (matrix);
}

t_map	create_map(char **lines)
{
	t_map	map;
	char	*charset;

	map.height = ft_atoi(lines[0]);
	charset = lines[0] + get_nb_size(map.height);
	map.empty = charset[0];
	map.obstacle = charset[1];
	map.full = charset[2];
	map.grid = lines + 1;
	map.width = ft_strlen(lines[1]);
	map.matrix = init_matrix(map);
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:07:06 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/26 14:00:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	init_border(t_map map)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < map.width)
	{
		map.matrix[0][x] = map.grid[0][x] == map.empty;
		x++;
	}
	y = 0;
	while (y < map.height)
	{
		map.matrix[y][0] = map.grid[y][0] == map.empty;
		y++;
	}
}

void	fill_matrix(t_map map)
{
	size_t	x;
	size_t	y;

	y = 1;
	while (y < map.height)
	{
		x = 1;
		while (x < map.width)
		{
			if (map.grid[y][x] == map.obstacle)
				map.matrix[y][x] = 0;
			else
				map.matrix[y][x] = 1 + min_of_three(
						map.matrix[y - 1][x],
						map.matrix[y][x - 1],
						map.matrix[y - 1][x - 1]
						);
			x++;
		}
		y++;
	}
}

t_bsq	init_bsq(size_t x, size_t y, size_t size)
{
	t_bsq	bsq;

	bsq.x = x;
	bsq.y = y;
	bsq.size = size;
	return (bsq);
}

t_bsq	find_bsq(t_map map)
{
	t_bsq	bsq;
	size_t	x;
	size_t	y;

	bsq = init_bsq(0, 0, 0);
	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			if (map.matrix[y][x] > bsq.size)
				bsq = init_bsq(x, y, map.matrix[y][x]);
			x++;
		}
		y++;
	}
	return (bsq);
}

t_bsq	solve(t_map map)
{
	init_border(map);
	fill_matrix(map);
	return (find_bsq(map));
}

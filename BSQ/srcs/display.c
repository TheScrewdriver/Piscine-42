/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:03:40 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/25 20:48:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	fill_bsq(t_map map, t_bsq bsq)
{
	size_t	dx;
	size_t	dy;

	dy = 0;
	while (dy < bsq.size)
	{
		dx = 0;
		while (dx < bsq.size)
		{
			map.grid[bsq.y - dy][bsq.x - dx] = map.full;
			dx++;
		}
		dy++;
	}
}

void	display_map(t_map map, t_bsq bsq)
{
	size_t	y;

	fill_bsq(map, bsq);
	y = 0;
	while (y < map.height)
	{
		ft_putstr_fd(map.grid[y], STDOUT_FILENO);
		ft_putchar('\n');
		++y;
	}
}

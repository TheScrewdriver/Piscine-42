/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:09:45 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/12 11:14:13 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#define SIZE 10
#define QUEEN_NB 10
#define EMPTY_CASE '-'
#define QUEEN 'X'

////////////////////////////////////////////////////////////////////////////////
/*
void	display_map(char map[SIZE][SIZE])
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			ft_putchar(' ');
			ft_putchar(map[i][j]);
			++j;
		}
		ft_putchar('\n');
		++i;
	}
	ft_putchar('\n');
}

void	ft_putchar(const char c)
{
	write(STDOUT_FILENO, &c, 1);
}
*/
////////////////////////////////////////////////////////////////////////////////

typedef struct s_pos
{
	size_t	x;
	size_t	y;
}				t_pos;

void	display_map(char map[SIZE][SIZE])
{
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			c = j + '0';
			if (map[j][i] == QUEEN)
				write(1, &c, 1);
			++j;
		}
		++i;
	}
	c = '\n';
	write(1, &c, 1);
}

t_pos	get_next_pos(t_pos pos)
{
	if (pos.x < SIZE - 1)
		++pos.x;
	else
	{
		pos.x = 0;
		++pos.y;
	}
	return (pos);
}

bool	is_valid_pos(char map[SIZE][SIZE], t_pos pos)
{
	size_t	i;

	i = 0;
	while (i < SIZE)
	{
		if (map[pos.y][i] == QUEEN && i != pos.x)
			return (false);
		if (map[i][pos.x] == QUEEN && i != pos.y)
			return (false);
		if (pos.x - i < SIZE && pos.y + i < SIZE
			&& map[pos.y + i][pos.x - i] == QUEEN)
			return (false);
		if (pos.x + i < SIZE && pos.y + i < SIZE
			&& map[pos.y + i][pos.x + i] == QUEEN)
			return (false);
		if (pos.x - i < SIZE && pos.y - i < SIZE
			&& map[pos.y - i][pos.x - i] == QUEEN)
			return (false);
		if (pos.x + i < SIZE && pos.y - i < SIZE
			&& map[pos.y - i][pos.x + i] == QUEEN)
			return (false);
		++i;
	}
	return (true);
}

int	backtrack(char map[SIZE][SIZE], t_pos pos, int queen_count)
{
	int	count;

	count = 0;
	if (queen_count == QUEEN_NB)
	{
		display_map(map);
		return (1);
	}
	while (pos.y < SIZE && queen_count < QUEEN_NB)
	{
		if (is_valid_pos(map, pos) == true)
		{
			map[pos.y][pos.x] = QUEEN;
			count += backtrack(map, get_next_pos(pos), queen_count + 1);
			map[pos.y][pos.x] = EMPTY_CASE;
		}
		pos = get_next_pos(pos);
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	char	map[SIZE][SIZE];
	t_pos	pos;
	long	comb_nb;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			map[i][j] = EMPTY_CASE;
			++j;
		}
		++i;
	}
	pos.x = 0;
	pos.y = 0;
	comb_nb = backtrack(map, pos, 0);
	return (comb_nb);
}

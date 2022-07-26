/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:55:03 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/25 21:24:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static bool	is_printable(const char c)
{
	return (FIRST_PRINTABLE <= c && c <= LAST_PRINTABLE);
}

static bool	is_valid_charset(
	const char empty,
	const char obstacle,
	const char full
)
{
	return (is_printable(empty) && is_printable(obstacle) && is_printable(full)
		&& empty != obstacle && obstacle != full && full != empty);
}

static bool	is_format_valid(const char *first_line)
{
	const size_t	len = ft_strlen(first_line);
	size_t			i;
	char			empty;
	char			obstacle;
	char			full;

	if (len <= 3)
		return (false);
	i = 0;
	while (i < len - 3)
	{
		if (first_line[i] < '0' || first_line[i] > '9')
			return (false);
		++i;
	}
	empty = first_line[len - 3];
	obstacle = first_line[len - 2];
	full = first_line[len - 1];
	return (is_valid_charset(empty, obstacle, full));
}

static bool	is_valid_line(
	const char *curr_line,
	const size_t expected_width,
	const char empty,
	const char obstacle
)
{
	size_t	i;

	i = 0;
	while (i < expected_width && curr_line[i] != '\0')
	{
		if (curr_line[i] != empty && curr_line[i] != obstacle)
			return (false);
		i++;
	}
	return (i == expected_width && curr_line[i] == '\0');
}

bool	is_valid_map(char **lines)
{
	size_t	format_len;
	size_t	i;
	size_t	first_width;
	size_t	height;

	if (lines[0] == NULL || lines[1] == NULL
		|| is_format_valid(lines[0]) == false)
		return (false);
	i = 1;
	format_len = ft_strlen(lines[0]);
	height = ft_atoi(lines[0]);
	first_width = ft_strlen(lines[1]);
	while (i < height + 1 && lines[i] != NULL)
	{
		if (is_valid_line(lines[i], first_width,
				lines[0][format_len - 3], lines[0][format_len - 2]) == false)
			return (false);
		i++;
	}
	return (lines[i] == NULL && i == height + 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:28:54 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/24 00:00:42 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_map	init_map(unsigned int input_key, char *input_value)
{
	t_map	map;

	map.key = input_key;
	map.value = input_value;
	return (map);
}

t_map	create_map(char *line)
{
	t_map	map;
	char	**data;

	data = ft_split(line, ":");
	map = init_map(ft_atou(data[0]), ft_create_value(data[1]));
	free_strings(data);
	return (map);
}

t_map	*create_maps(char *file)
{
	size_t	i;
	size_t	size;
	char	**lines;
	t_map	*maps;

	lines = ft_split(file, "\n");
	if (are_lines_valid(lines) == true)
	{
		size = get_array_size(lines);
		maps = (t_map *)malloc((size + 1) * sizeof(t_map));
		if (maps != NULL)
		{
			i = 0;
			while (i < size)
			{
				maps[i] = create_map(lines[i]);
				++i;
			}
			maps[size] = init_map(0, NULL);
		}
	}
	else
		maps = NULL;
	free_strings(lines);
	return (maps);
}

void	display_key(unsigned int nb, t_map *maps)
{
	while (maps->value != NULL)
	{
		if (nb == maps->key)
		{
			ft_putstr_fd(maps->value, STDOUT_FILENO);
			break ;
		}
		++maps;
	}
}

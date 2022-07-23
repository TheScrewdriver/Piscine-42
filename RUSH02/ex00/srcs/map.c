/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:28:54 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/23 19:34:14 by rbroque          ###   ########.fr       */
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

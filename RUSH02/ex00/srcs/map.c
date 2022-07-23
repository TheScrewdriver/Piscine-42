/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:16:55 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/23 17:51:04 by rbroque          ###   ########.fr       */
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
	char	**data;

	data = ft_split(line, ":");
	return (init_map(ft_atoi(data[0]), ft_create_value(data[1])));
}

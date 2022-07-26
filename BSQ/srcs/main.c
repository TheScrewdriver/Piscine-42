/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:45:17 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/26 12:32:28 by axbrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

bool	solving_bsq(char *file_content)
{
	t_map	map;
	char	**lines;
	bool	is_error;

	is_error = false;
	lines = ft_split_lines(file_content);
	if (lines != NULL && is_valid_map(lines) == true)
	{
		map = create_map(lines);
		display_map(map, solve(map));
		free_matrix(map.matrix, map.height);
	}
	else
		is_error = true;
	free(file_content);
	free_lines(lines);
	return (is_error);
}

bool	solving_map(char *file_content, int ret_value)
{
	bool	is_error;

	if (file_content != NULL)
		is_error = solving_bsq(file_content);
	else
		is_error = true;
	ret_value = handle_error(is_error, ret_value);
	return (ret_value);
}

int	main(int ac, char **av)
{
	char	*file_content;
	int		ret_value;

	++av;
	ret_value = EXIT_SUCCESS;
	if (ac == 1)
	{
		file_content = get_input();
		ret_value = solving_map(file_content, ret_value);
	}
	else
	{
		while (*av != NULL)
		{
			file_content = get_file(*av);
			ret_value = solving_map(file_content, ret_value);
			if (ac > 2 && *(av + 1) != NULL)
				ft_putchar('\n');
			++av;
		}
	}
	return (ret_value);
}

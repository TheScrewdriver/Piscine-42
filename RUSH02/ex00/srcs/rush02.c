/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:57:50 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/23 18:01:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

size_t	get_array_size(char **array)
{
	size_t	size;

	size = 0;
	while (array[size] != NULL)
		++size;
	return (size);
}

t_map	*create_maps(char *file)
{
	size_t	i;
	size_t	size;
	char	**lines;
	t_map	*maps;

	lines = ft_split(file, "\n");
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
	free_strings(lines);
	return (maps);
}

bool	are_lines_valid(const char **lines)
{
	while (*lines != NULL)
	{
		if (is_valid_line(*lines) == false)
			return (false);
		++lines;
	}
	return (true);
}

void	display_map(t_map map)
{
	printf("key --> %d; value --> %s\n", map.key, map.value);
}

int	main(int ac, char **av)
{

	/*
	   (void)ac;
	   (void)av;
	   printf(">>> IS_VALID_LINE <<<\n\n");
	   printf("[] --> %d\n", is_valid_line(""));
	   printf("[42] --> %d\n", is_valid_line("42"));
	   printf("[:] --> %d\n", is_valid_line(":"));
	   printf("[1::] --> %d\n", is_valid_line("1::"));
	   printf("[50   :hello] --> %d\n", is_valid_line("50   :hello"));
	   printf("[sai: ouah] --> %d\n", is_valid_line("sai: ouah"));
	   printf("[42  :  forty_two] --> %d\n", is_valid_line("42  :  forty_two"));
	 */
	char	*file;
	t_map	*maps;

	if (ac == 2)
	{
		file = get_file(av[1]);
		if (file != NULL)
		{
			maps = create_maps(file);
			while ((*maps).value != NULL)
			{
				display_map(*maps);
				++maps;
			}
	//		free(file);
//			free(maps);
		}
	}
	return (0);
}

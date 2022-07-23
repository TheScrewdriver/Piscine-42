/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:57:50 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/23 16:14:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

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
	size_t	i;
	char	*file;
	char	**lines;

	if (ac == 2)
	{
		i = 0;
		file = get_file(av[1]);
		if (file != NULL)
		{
			lines = ft_split(file, "\n");
			while (lines[i] != NULL)
			{
				printf("%s\n", lines[i]);
				if (is_valid_line(lines[i]) == false)
				{
					display_error();
					break;
				}
				++i;
			}
			free(file);
			free_strings(lines);
		}
	}
	return (0);
}

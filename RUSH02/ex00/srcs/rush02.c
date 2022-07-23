/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:57:50 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/23 12:05:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int ac, char **av)
{
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
				++i;
			}
			free(file);
			free_strings(lines);
		}
	}
	return (0);
}

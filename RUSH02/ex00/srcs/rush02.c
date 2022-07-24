/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:57:50 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/24 11:28:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int ac, char **av)
{
	char	*file_path;
	char	*dict;
	t_map	*maps;
	long	nb;

	file_path = DEFAULT_PATH;
	if (ac == 2 || ac == 3)
	{
		if (ac == 3)
			file_path = av[ac - 2];
		dict = get_file(file_path);
		if (dict != NULL)
		{
			maps = create_maps(dict);
			nb = ft_atou(av[ac - 1]);
			if (maps == NULL)
				ft_putstr_fd(ERROR_DICT, STDERR_FILENO);
			else
			{
				print_nb(nb, maps);
				ft_putstr_fd("\n", STDOUT_FILENO);
				free_maps(&maps);
			}
			free(dict);
		}
	}
	return (EXIT_SUCCESS);
}

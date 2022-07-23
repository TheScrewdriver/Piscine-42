/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:57:50 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/23 22:37:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int ac, char **av)
{
	char	*file_path;
	char	*dict;
	t_map	*maps;
	long	nb;

	if (ac == 3)
	{
		file_path = av[1];
		dict = get_file(file_path);
		if (dict != NULL)
		{
			maps = create_maps(dict);
			nb = ft_atou(av[2]);
			if (nb == -1)
				ft_putstr_fd(ERROR_NB, STDERR_FILENO);
			else
				print_nb(nb, maps);
			free(dict);
			free_maps(&maps);
		}
	}
	return (EXIT_SUCCESS);
}

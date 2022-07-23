/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:57:50 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/23 21:54:38 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int ac, char **av)
{
	char	*file;
	t_map	*maps;

	if (ac == 3)
	{
		file = get_file(av[1]);
		if (file != NULL)
		{
			maps = create_maps(file);
			print_nb(ft_atou(av[2]), maps);
			free(file);
			free_maps(&maps);
		}
	}
	return (0);
}

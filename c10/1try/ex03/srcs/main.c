/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:08:34 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/21 13:05:51 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	main(int ac, char **av)
{
	int	i;
	int	ret_value;

	ret_value = EXIT_SUCCESS;
	++av;
	--ac;
	while (i < ac)
	{
		ft_print_memory(av[i]);
		++i;
	}
	return (ret_value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:53:02 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/24 11:23:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	get_divider(unsigned int nb)
{
	const unsigned int	pow_of_ten[4] = {1000000000, 1000000, 1000, 100};
	int					i;

	i = 0;
	while (i < 4)
	{
		if (pow_of_ten[i] <= nb)
			return (pow_of_ten[i]);
		++i;
	}
	return (1);
}

void	print_below_hundred(unsigned int nb, t_map *maps)
{
	if (nb <= 20)
		display_key(nb, maps);
	else
	{
		display_key((nb / 10) * 10, maps);
		ft_putstr_fd(" ", STDOUT_FILENO);
		if (nb % 10 > 0)
			display_key(nb % 10, maps);
	}
}

void	print_nb(long nb, t_map *maps)
{
	int	divider;

	if (nb == -1)
	{
		ft_putstr_fd(ERROR_NB, STDERR_FILENO);
		return ;
	}
	if (nb < 100)
		print_below_hundred(nb, maps);
	else
	{
		divider = get_divider(nb);
		print_nb(nb / divider, maps);
		ft_putstr_fd(" ", STDOUT_FILENO);
		display_key(divider, maps);
		ft_putstr_fd(" ", STDOUT_FILENO);
		print_nb(nb % divider, maps);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:08:34 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/17 22:16:58 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	do_op(const int nb1, const char *operator, const int nb2)
{
	const char	*operators[] = {"+", "-", "*", "/", "%", NULL};
	static long	(*op_ft[])(const int, const int)
		= {add, sub, mult, division, mod};
	long		result;
	size_t		rank;

	result = 0;
	rank = 0;
	while (operators[rank] != NULL && ft_strcmp(operators[rank], operator) != 0)
		++rank;
	if (operators[rank] != NULL)
	{
		if (ft_strcmp(operators[rank], "/") == 0 && nb2 == 0)
		{
			ft_putstr(DIVISION_ZERO);
			return ;
		}
		else if (ft_strcmp(operators[rank], "%") == 0 && nb2 == 0)
		{
			ft_putstr(MOD_ZERO);
			return ;
		}
		result = op_ft[rank](nb1, nb2);
	}
	ft_putnbr(result);
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		do_op(ft_atoi(av[1]), av[2], ft_atoi(av[3]));
		ft_putchar('\n');
	}
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:47:14 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/06 12:18:38 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAX_DIGIT '9'

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display_numbers(const char nb1, const char nb2, const char nb3)
{
	ft_putchar(nb1);
	ft_putchar(nb2);
	ft_putchar(nb3);
	if (nb1 != nb2 - 1 || nb2 != nb3 - 1 || nb3 != MAX_DIGIT)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = '0';
	while (nb1 <= MAX_DIGIT)
	{
		nb2 = nb1 + 1;
		while (nb2 <= MAX_DIGIT)
		{
			nb3 = nb2 + 1;
			while (nb3 <= MAX_DIGIT)
			{
				display_numbers(nb1, nb2, nb3);
				++nb3;
			}
			++nb2;
		}
		++nb1;
	}
}

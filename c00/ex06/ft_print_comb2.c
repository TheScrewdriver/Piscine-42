/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:21:17 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/06 16:47:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define INIT_NB 0
#define MAX_NB 99
#define DIGIT_NB 2

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_nb(int nb, const int digit_nb)
{
	if (digit_nb > 0)
	{
		print_nb(nb / 10, digit_nb - 1);
		ft_putchar(nb % 10 + '0');
	}
}

void	ft_print_comb2(void)
{
	int	nb1;
	int	nb2;

	nb1 = 0;
	while (nb1 <= MAX_NB)
	{
		nb2 = nb1 + 1;
		while (nb2 <= MAX_NB)
		{
			print_nb(nb1, DIGIT_NB);
			ft_putchar(' ');
			print_nb(nb2, DIGIT_NB);
			if (nb2 < MAX_NB || nb1 < MAX_NB - 1)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			++nb2;
		}
		++nb1;
	}
}

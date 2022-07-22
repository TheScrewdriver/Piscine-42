/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:25:09 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/06 16:44:38 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	display_pos_number(const unsigned int nb)
{
	if (nb != 0)
	{
		display_pos_number(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

unsigned int	get_abs(const int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		ft_putchar('0');
	else
	{
		if (nb < 0)
			ft_putchar('-');
		display_pos_number(get_abs(nb));
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:25:09 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/17 21:51:10 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	display_pos_number(const unsigned long nb)
{
	if (nb != 0)
	{
		display_pos_number(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

unsigned long	get_abs(const long nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	ft_putnbr(long nb)
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

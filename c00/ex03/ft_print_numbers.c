/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:46:03 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/06 09:46:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define FIRST_NB '0'
#define LAST_NB '9'

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	char	nb;

	nb = FIRST_NB;
	while (nb <= LAST_NB)
	{
		ft_putchar(nb);
		++nb;
	}
}

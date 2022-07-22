/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:46:10 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/06 09:46:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define NEGATIVE 'N'
#define POSITIVE 'P'

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	if (n < 0)
		ft_putchar(NEGATIVE);
	else
		ft_putchar(POSITIVE);
}

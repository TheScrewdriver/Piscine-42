/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:00:04 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/26 14:00:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

size_t	min_of_three(size_t n1, size_t n2, size_t n3)
{
	if (n1 < n2)
	{
		if (n1 < n3)
			return (n1);
		else
			return (n3);
	}
	if (n2 < n3)
		return (n2);
	return (n3);
}

size_t	get_nb_size(int nb)
{
	size_t	size;

	size = (nb <= 0);
	while (nb != 0)
	{
		nb /= 10;
		++size;
	}
	return (size);
}

int	ft_atoi(char *str)
{
	unsigned long	nb;

	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		if (nb > INT_MAX)
			return (-1);
		++str;
	}
	return ((int)nb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:31:51 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/12 21:37:07 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

long	get_abs(long nb)
{
	long	abs;

	abs = nb;
	if (abs < 0)
		return (-abs);
	return (abs);
}

int	*ft_range(int min, int max)
{
	long	i;
	long	size;
	int		*array;

	if (max <= min)
		return (NULL);
	size = get_abs((long)((long)max - (long)min));
	array = (int *)malloc(size * sizeof(int));
	if (array != NULL)
	{
		i = 0;
		while (i < size)
		{
			array[i] = min + i;
			++i;
		}
	}
	return (array);
}

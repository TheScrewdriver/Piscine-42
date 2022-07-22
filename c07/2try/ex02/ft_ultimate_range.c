/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:46:34 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/12 22:28:37 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = ft_range(min, max);
	if (*range == NULL)
		return (-1);
	return (get_abs((long)max - (long)min));
}

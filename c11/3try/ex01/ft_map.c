/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:39:49 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/17 18:51:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*new;

	i = 0;
	new = (int *)malloc(length * sizeof(int));
	if (new != NULL)
	{
		while (i < length)
		{
			new[i] = f(tab[i]);
			++i;
		}
	}
	return (new);
}

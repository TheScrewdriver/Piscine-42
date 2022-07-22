/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:29:57 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/07 11:27:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp1;
	int	tmp2;

	if (tab != NULL)
	{
		i = 0;
		while (i < size - i)
		{
			tmp1 = tab[size - 1 - i];
			tmp2 = tab[i];
			tab[i] = tmp1;
			tab[size - 1 - i] = tmp2;
			++i;
		}
	}
}

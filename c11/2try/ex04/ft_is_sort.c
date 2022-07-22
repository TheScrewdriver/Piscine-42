/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:21:59 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/18 12:03:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	way_sort;

	i = 0;
	way_sort = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) != 0)
		{
			if (way_sort == 0)
				way_sort = f(tab[i], tab[i + 1]);
			else if (f(tab[i], tab[i + 1]) != way_sort)
				return (0);
		}
		++i;
	}
	return (1);
}

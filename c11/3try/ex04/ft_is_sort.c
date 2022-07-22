/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:21:59 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/18 21:07:19 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_sign(const int nb)
{
	if (nb > 0)
		return (1);
	if (nb < 0)
		return (-1);
	return (0);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sign;
	int	way_sort;

	i = 0;
	way_sort = 0;
	while (i < length - 1)
	{
		sign = get_sign(f(tab[i], tab[i + 1]));
		if (sign != 0)
		{
			if (way_sort == 0)
				way_sort = sign;
			else if (sign != way_sort)
				return (0);
		}
		++i;
	}
	return (1);
}

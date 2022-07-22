/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:53:34 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/11 09:04:00 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	new_nb;

	if (power < 0)
		return (0);
	i = 0;
	new_nb = 1;
	while (i < power)
	{
		new_nb *= nb;
		++i;
	}
	return (new_nb);
}

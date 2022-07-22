/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:20:30 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/12 16:45:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long	divider;

	divider = 2;
	if (nb <= 1)
		return (0);
	else if (nb == 2)
		return (1);
	while (nb % divider != 0 && divider * divider < nb)
		++divider;
	return (nb % divider != 0);
}

int	ft_find_next_prime(int nb)
{
	int	next;

	next = nb;
	if (nb < 2)
		return (2);
	while (ft_is_prime(next) == 0)
		++next;
	return (next);
}

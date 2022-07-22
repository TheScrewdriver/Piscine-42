/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:17:27 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/11 13:19:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	divider;

	divider = 2;
	if (nb <= 1)
		return (0);
	else if (nb == 2)
		return (1);
	while (nb % divider != 0 && divider < nb / 2)
		++divider;
	return (nb % divider != 0);
}

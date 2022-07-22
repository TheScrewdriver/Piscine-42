/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:25:57 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/06 17:08:01 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	display_nb(const int nb, const int digits_nb)
{
	if (digits_nb > 0)
	{
		display_nb(nb / 10, digits_nb - 1);
		ft_putchar(nb % 10 + '0');
	}
}

int	is_last(int comb, const int initial_digits)
{
	int	last_digit;
	int	max_digit_value;

	max_digit_value = 9;
	while (max_digit_value >= 10 - initial_digits)
	{
		last_digit = comb % 10;
		comb /= 10;
		if (last_digit != max_digit_value)
			return (0);
		--max_digit_value;
	}
	return (1);
}

void	backtrack(const int prev, const int remaining_digits, const int comb,
		const int initial_digits)
{
	int	i;

	if (remaining_digits == 0)
	{
		display_nb(comb, initial_digits);
		if (is_last(comb, initial_digits) == 0)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
	else
	{
		i = prev;
		while (i < 10)
		{
			backtrack(i + 1, remaining_digits - 1, 10 * comb + i,
				initial_digits);
			++i;
		}
	}
}

void	ft_print_combn(int n)
{
	backtrack(0, n, 0, n);
}

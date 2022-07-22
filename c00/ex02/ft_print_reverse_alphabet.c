/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:45:53 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/06 09:45:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define FIRST_LETTER 'a'
#define LAST_LETTER 'z'

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_reverse_alphabet(void)
{
	char	letter;

	letter = LAST_LETTER;
	while (letter >= FIRST_LETTER)
	{
		ft_putchar(letter);
		--letter;
	}
}

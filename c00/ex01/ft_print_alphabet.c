/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:45:41 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/06 09:45:42 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define FIRST_LETTER 'a'
#define LAST_LETTER 'z'

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet(void)
{
	char	letter;

	letter = FIRST_LETTER;
	while (letter <= LAST_LETTER)
	{
		ft_putchar(letter);
		++letter;
	}
}

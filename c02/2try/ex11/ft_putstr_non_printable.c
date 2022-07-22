/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:04:02 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/09 18:38:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#define FIRST_PRINTABLE 32
#define LAST_PRINTABLE 126
#define BACKSLASH '\\'
#define HEX "0123456789abcdef"

void	ft_putchar(const unsigned char c)
{
	write(1, &c, 1);
}

bool	is_printable(const unsigned char c)
{
	return (c >= FIRST_PRINTABLE && c <= LAST_PRINTABLE);
}

void	print_hex(const unsigned char nb)
{
	ft_putchar(HEX[nb / 16]);
	ft_putchar(HEX[nb % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	if (str != NULL)
	{	
		while (*str != '\0')
		{		
			if (is_printable(*str) == true)
				ft_putchar(*str);
			else
			{
				ft_putchar(BACKSLASH);
				print_hex(*str);
			}
			++str;
		}
	}
}

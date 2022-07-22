/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:29:36 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/11 20:07:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define FIRST_PRINTABLE 32
#define LAST_PRINTABLE 126
#define HEX "0123456789abcdef"
#define SEPARATOR ':'
#define DOT '.'
#define SPACE ' '

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	print_hex(const unsigned long long nb, const size_t size)
{
	if (size > 0)
	{
		print_hex(nb / 16, size - 1);
		ft_putchar(HEX[nb % 16]);
	}
}

void	print_hex_value(void *addr, unsigned int size)
{
	size_t	j;

	j = 0;
	if (size > 0)
	{
		print_hex((unsigned long)(addr), 16);
		ft_putchar(SEPARATOR);
		ft_putchar(SPACE);
		while (j < 16)
		{
			if (size > 0)
			{
				print_hex(((char *)(addr))[j], 2);
				--size;
			}
			else
			{
				ft_putchar(SPACE);
				ft_putchar(SPACE);
			}
			if (j % 2 == 1)
				ft_putchar(SPACE);
			++j;
		}
	}
}

void	print_line(void *addr, unsigned int *size)
{
	size_t	j;
	char	c;

	j = 0;
	print_hex_value(addr, *size);
	while (j < 16 && *size > 0)
	{
		c = ((char *)(addr))[j];
		if (c >= FIRST_PRINTABLE && c <= LAST_PRINTABLE)
			ft_putchar(c);
		else
			ft_putchar(DOT);
		++j;
		--(*size);
	}
	ft_putchar('\n');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	size_t			i;
	const size_t	line_nb = size / 16 + (size % 16 > 0);	

	if (addr != NULL && size > 0)
	{
		i = 0;
		while (i < line_nb)
		{
			print_line(addr + i * 16, &size);
			++i;
		}
	}
	return (addr);
}

int	main(void)
{
	char	str[] = "lolipop";

	ft_print_memory(str, 150);
	return (0);
}

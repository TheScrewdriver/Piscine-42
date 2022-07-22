/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:16:43 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/11 16:37:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(const char c)
{
	write(STDOUT_FILENO, &c, sizeof(c));
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

bool	is_valid_base(const char *base)
{
	size_t	i;
	size_t	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (false);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] != '-' && base[i] != '+')
		{
			j = i + 1;
			while (base[j] != '\0')
			{
				if (base[i] == base[j])
					return (false);
				++j;
			}
		}
		else
			return (false);
		++i;
	}
	return (true);
}

void	print_nb(unsigned int nbr, char *base, const size_t base_size)
{
	if (nbr != 0)
	{
		print_nb(nbr / base_size, base, base_size);
		ft_putchar(base[nbr % base_size]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	new_nbr;

	if (base != NULL && is_valid_base(base) == true)
	{
		if (nbr == 0)
			ft_putchar(*base);
		else
		{
			if (nbr < 0)
			{
				ft_putchar('-');
				new_nbr = -(unsigned int)(nbr);
			}
			else
				new_nbr = nbr;
			print_nb(new_nbr, base, ft_strlen(base));
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	if (ac > 2)
		ft_putnbr_base(atoi(av[1]), av[2]);
}

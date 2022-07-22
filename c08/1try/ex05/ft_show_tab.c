/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:14:51 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/15 00:06:43 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>
#include <stdlib.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

void	display_pos_number(const unsigned int nb)
{
	char	digit;

	if (nb != 0)
	{
		digit = nb % 10 + '0';
		display_pos_number(nb / 10);
		write(1, &digit, 1);
	}
}

void	ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}

void	print_tab(struct s_stock_str *par)
{
	char	c;

	ft_putstr(par->str);
	ft_putstr("\n");
	if (par->size <= 0)
	{
		c = '0';
		write(1, &c, 1);
	}
	else
		display_pos_number(par->size);
	ft_putstr("\n");
	ft_putstr(par->copy);
	ft_putstr("\n");
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str != NULL)
	{
		print_tab(par);
		++par;
	}
}

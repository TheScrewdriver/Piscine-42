/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:42:22 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/17 21:51:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

char	*skip_whitespaces(char *str)
{
	while ((*str >= FIRST_WHITESPACE && *str <= LAST_WHITESPACE)
		|| (*str == SPACE))
		++str;
	return (str);
}

int	get_sign(const char *str)
{
	size_t	sign;

	sign = 0;
	while ((*str != '\0') && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			++sign;
		++str;
	}
	if (sign % 2 == 1)
		return (-1);
	return (1);
}

int	ft_atoi(char *str)
{
	int				sign;
	unsigned int	nb;

	nb = 0;
	str = skip_whitespaces(str);
	sign = get_sign(str);
	while (*str == '+' || *str == '-')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		++str;
	}
	return (sign * nb);
}

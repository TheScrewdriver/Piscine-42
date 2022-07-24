/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:27:50 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/23 23:52:01 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*skip_whitespaces(char *str)
{
	while ((*str >= FIRST_WHITESPACE && *str <= LAST_WHITESPACE)
		|| (*str == SPACE))
		++str;
	return (str);
}

long	ft_atou(char *str)
{
	long	nb;

	nb = 0;
	str = skip_whitespaces(str);
	while (*str == '+')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		if (nb > UINT_MAX)
			return (-1);
		++str;
	}
	if (*str != '\0')
		return (-1);
	return ((unsigned int)nb);
}

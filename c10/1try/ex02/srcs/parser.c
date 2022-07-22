/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:03:29 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/21 11:47:13 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

bool	is_whitespace(const char c)
{
	return ((c >= FIRST_WHITESPACE && c <= LAST_WHITESPACE) || (c == SPACE));
}

int	get_numb(const char *str)
{
	int	nb;

	nb = 0;
	while (is_whitespace(*str) == true)
		++str;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		++str;
	}
	return (nb);
}

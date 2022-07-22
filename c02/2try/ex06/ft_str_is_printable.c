/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:44:52 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/08 09:52:05 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

#define FIRST_PRINTABLE 32
#define LAST_PRINTABLE 126

bool	is_printable(const char c)
{
	return (c >= FIRST_PRINTABLE && c <= LAST_PRINTABLE);
}

int	ft_str_is_printable(char *str)
{
	if (str == NULL || *str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (is_printable(*str) == false)
			return (0);
		++str;
	}
	return (1);
}

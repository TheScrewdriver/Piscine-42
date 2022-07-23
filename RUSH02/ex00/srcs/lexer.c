/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:56:42 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/23 17:29:28 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static size_t	skip_whitespaces(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' && str[i] != '\0')
		++i;
	return (i);
}

bool	is_valid_line(const char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*str != SPACE && *str != SEPARATOR
		&& *str >= '0' && *str <= '9' && *str != '\0')
	{
		++i;
		++str;
	}
	str += skip_whitespaces(str);
	if (*str == SEPARATOR)
	{
		++str;
		while (*str != '\0')
		{
			++j;
			++str;
		}
	}
	return (i > 0 && j > 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 08:15:23 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/08 10:57:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

#define TO_UPPER_OFFSET 32

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= TO_UPPER_OFFSET;
	return (c);
}

char	to_low(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += TO_UPPER_OFFSET;
	return (c);
}

bool	is_alphnum(char c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	size_t	i;
	bool	is_word;

	if (str != NULL)
	{
		is_word = false;
		i = 0;
		while (str[i] != '\0')
		{
			if (is_alphnum(str[i]) == true)
			{
				if (is_word == false)
				{
					str[i] = to_upper(str[i]);
					is_word = true;
				}
				else
					str[i] = to_low(str[i]);
			}
			else
				is_word = false;
			++i;
		}
	}
	return (str);
}

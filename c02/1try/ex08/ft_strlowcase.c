/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 23:17:44 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/08 08:11:05 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define TO_UPPER_OFFSET 32

char	to_low(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += TO_UPPER_OFFSET;
	return (c);
}

char	*ft_strlowcase(char *str)
{
	size_t	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			str[i] = to_low(str[i]);
			++i;
		}
	}
	return (str);
}

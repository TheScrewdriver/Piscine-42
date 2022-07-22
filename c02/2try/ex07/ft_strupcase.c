/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:51:07 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/07 23:00:00 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define TO_UPPER_OFFSET 32

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= TO_UPPER_OFFSET;
	return (c);
}

char	*ft_strupcase(char *str)
{
	size_t	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			str[i] = to_upper(str[i]);
			++i;
		}
	}
	return (str);
}

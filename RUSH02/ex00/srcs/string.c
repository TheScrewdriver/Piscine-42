/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:29:20 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/23 21:43:41 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

size_t     ft_strlen(const char *str)
{
	size_t     i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

size_t	get_array_size(char **array)
{
	size_t	size;

	size = 0;
	while (array[size] != NULL)
		++size;
	return (size);
}

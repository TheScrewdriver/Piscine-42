/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:41:33 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/10 13:46:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

size_t	get_min_size(const size_t size1, const size_t size2)
{
	if (size1 < size2)
		return (size1);
	return (size2);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			++i;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int nb)
{
	const size_t	size_dest = ft_strlen(dest);
	const size_t	size_src = ft_strlen(src);
	const size_t	min_size = get_min_size(size_dest, nb);

	ft_strlcpy(dest + size_dest, src, nb - size_dest);
	return (min_size + size_src);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:29:36 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/13 00:43:18 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (dest[i] != '\0')
		++i;
	ft_strcpy(dest + i, src);
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

size_t	get_total_size(char **strs, const size_t size, const char *sep)
{
	const size_t	sep_size = ft_strlen(sep);
	size_t			i;
	size_t			total_size;

	i = 0;
	total_size = 0;
	while (i < size)
	{
		total_size += ft_strlen(strs[i]);
		if (i < size - 1)
			total_size += sep_size;
		++i;
	}
	return (total_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	const size_t	total_size = get_total_size(strs, size, sep);
	int				i;
	char			*new;

	new = (char *)malloc((total_size + 1) * sizeof(char));
	if (new != NULL)
	{
		i = 0;
		*new = '\0';
		while (i < size)
		{
			ft_strcat(new, strs[i]);
			if (i < size - 1)
				ft_strcat(new, sep);
			++i;
		}
		new[total_size] = '\0';
	}
	return (new);
}

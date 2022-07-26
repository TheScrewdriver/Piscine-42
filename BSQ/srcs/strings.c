/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:14:02 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/25 17:27:29 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

void	ft_putchar(const char c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	ft_putstr_fd(const char *str, const int fd)
{
	write(fd, str, ft_strlen(str));
}

char	*ft_strchr(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (str + i);
		++i;
	}
	return (NULL);
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

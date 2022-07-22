/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:49:29 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/14 23:31:06 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(const char *const str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

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

char	*ft_strdup(char *src)
{
	const int		size = ft_strlen(src);
	char			*new;

	new = (char *)malloc((size + 1) * sizeof(char));
	if (new != NULL)
		ft_strcpy(new, src);
	return (new);
}

struct s_stock_str	init_stock(int size, char *str, char *str_dup)
{
	t_stock_str	new;

	new.size = size;
	new.str = str;
	new.copy = str_dup;
	return (new);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*new;
	int			i;

	new = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (new != NULL)
	{
		i = 0;
		while (i < ac)
		{
			new[i] = init_stock(ft_strlen(av[i]), av[i], ft_strdup(av[i]));
			++i;
		}
		new[ac] = init_stock(0, NULL, NULL);
	}
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:29:03 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/23 19:29:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static size_t	ft_first_space(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == SPACE)
		i++;
	return (i);
}

static size_t	ft_lst_space(const char *str)
{
	size_t	size;
	size_t	j;

	size = ft_strlen(str);
	j = 0;
	while (j < size && str[size - 1 - j] == SPACE)
		j++;
	return (j);
}

char	*ft_create_value(char *str)
{
	const size_t	first_spaces = ft_first_space(str);
	const size_t	new_len = ft_strlen(str) - first_spaces - ft_lst_space(str);
	char			*value;

	value = (char *)malloc(sizeof(char) * (new_len + 1));
	if (value == NULL)
		return(value);
	ft_strncpy(value, str + first_spaces, new_len);
	value[new_len] = '\0';
	return(value);
}

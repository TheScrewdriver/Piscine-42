/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:46:09 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/26 13:57:43 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static ssize_t	get_lines_nb(char *str)
{
	ssize_t	count;
	bool	new_line;

	count = 0;
	new_line = true;
	while (*str != '\0')
	{
		if (*str == '\n')
		{
			if (new_line == true)
				return (-1);
			new_line = true;
			++count;
		}
		else
			new_line = false;
		++str;
	}
	if (new_line == false)
		return (-1);
	return (count);
}

static size_t	*get_sizes(char *str, size_t count_lines)
{
	size_t	*sizes;
	size_t	i;
	size_t	j;

	sizes = (size_t *)malloc((count_lines + 1) * sizeof(size_t));
	if (sizes != NULL)
	{
		i = 0;
		while (i < count_lines)
		{
			j = 0;
			while (*str != '\0' && *str != '\n')
			{
				++j;
				++str;
			}
			if (*str != '\0')
				++str;
			sizes[i] = j;
			++i;
		}
		sizes[count_lines] = 0;
	}
	return (sizes);
}

void	fill_line(char **lines, char **str, size_t i, size_t size)
{
	ft_strncpy(lines[i], *str, size);
	*str += size + 1;
	lines[i][size] = '\0';
}

char	**ft_split_lines(char *str)
{
	const ssize_t	count_lines = get_lines_nb(str);
	ssize_t			i;
	size_t			*sizes;
	char			**lines;

	if (count_lines == -1)
		return (NULL);
	sizes = get_sizes(str, count_lines);
	lines = (char **)malloc((count_lines + 1) * sizeof(char *));
	if (lines != NULL)
	{
		i = 0;
		while (i < count_lines)
		{
			lines[i] = (char *)malloc((sizes[i] + 1) * sizeof(char));
			if (lines[i] != NULL)
				fill_line(lines, &str, i, sizes[i]);
			++i;
		}
		lines[count_lines] = NULL;
	}
	free(sizes);
	return (lines);
}

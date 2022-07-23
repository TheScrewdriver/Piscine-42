/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:46:09 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/23 10:54:00 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

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
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		++i;
	}
	return (dest);
}

size_t	get_count_words(char *str, char *charset)
{
	size_t	count;
	bool	is_word;

	count = 0;
	is_word = false;
	while (*str != '\0')
	{
		if (ft_strchr(charset, *str) != NULL)
		{
			if (is_word == true)
			{
				++count;
				is_word = false;
			}
		}
		else
			is_word = true;
		++str;
	}
	return (count + (is_word == true));
}

size_t	*get_sizes(char *str, char *charset, size_t count_words)
{
	size_t	*sizes;
	size_t	i;
	size_t	j;

	sizes = (size_t *)malloc((count_words + 1) * sizeof(size_t));
	if (sizes != NULL)
	{
		i = 0;
		while (i < count_words)
		{
			j = 0;
			while (ft_strchr(charset, *str) != NULL)
				++str;
			while (*str != '\0' && ft_strchr(charset, *str) == NULL)
			{
				++j;
				++str;
			}
			sizes[i] = j;
			++i;
		}
		sizes[count_words] = 0;
	}
	return (sizes);
}

char	**ft_split(char *str, char *charset)
{
	const size_t	count_words = get_count_words(str, charset);
	size_t			*sizes;
	size_t			i;
	char			**strs;

	sizes = get_sizes(str, charset, count_words);
	strs = (char **)malloc((count_words + 1) * sizeof(char *));
	if (strs != NULL)
	{
		i = 0;
		strs[count_words] = NULL;
		while (i < count_words)
		{
			strs[i] = (char *)malloc((sizes[i] + 1) * sizeof(char));
			while (ft_strchr(charset, *str) != NULL)
				++str;
			if (strs[i] != NULL)
				ft_strncpy(strs[i], str, sizes[i]);
			str += sizes[i];
			strs[i][sizes[i]] = '\0';
			++i;
		}
	}
	free(sizes);
	return (strs);
}

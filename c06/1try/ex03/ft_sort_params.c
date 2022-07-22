/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:55:44 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/12 13:01:56 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define NEW_LINE "\n"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

void	ft_putstr(const char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		c1 = s1[i];
		c2 = s2[i];
		if (c1 != c2)
			return (c1 - c2);
		++i;
	}
	return (0);
}

void	sort_list(char **strs_list, int size)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < size - 1)
	{
		if (ft_strcmp(strs_list[i], strs_list[i + 1]) > 0)
		{
			tmp = strs_list[i];
			strs_list[i] = strs_list[i + 1];
			strs_list[i + 1] = tmp;
			i = 0;
		}
		else
			++i;
	}
}

int	main(int ac, char **av)
{
	int	i;

	++av;
	sort_list(av, ac - 1);
	i = 0;
	while (i < ac - 1)
	{
		ft_putstr(av[i]);
		ft_putstr(NEW_LINE);
		++i;
	}
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:20:20 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/18 00:23:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(char **str1, char **str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	size_t	i;

	i = 0;
	if (tab[i] != NULL)
	{
		while (tab[i + 1] != NULL)
		{
			if (cmp(tab[i], tab[i + 1]) > 0)
			{
				ft_swap(tab + i, tab + i + 1);
				i = 0;
			}
			else
				++i;
		}
	}
}

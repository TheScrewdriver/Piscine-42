/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:20:07 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/13 18:04:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

#define SPACE ' '
#define FIRST_WHITESPACE 9
#define LAST_WHITESPACE 13

size_t	get_rank(const char *str, const char c)
{
	int	rank;

	rank = 0;
	while (str[rank] != '\0' && str[rank] != c)
		++rank;
	return (rank);
}

char	*skip_whitespaces(char *str)
{
	while ((*str >= FIRST_WHITESPACE && *str <= LAST_WHITESPACE)
		|| (*str == SPACE))
		++str;
	return (str);
}

bool	is_matching_base(const char *base, const char *str)
{
	size_t	i;
	size_t	j;
	bool	match;

	i = 0;
	match = false;
	while (str[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (str[i] == base[j] || str[i] == '-' || str[i] == '+'
				|| (str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			{
				match = true;
				break ;
			}
			++j;
		}
		if (match == false)
			return (false);
		match = false;
		++i;
	}
	return (true);
}

bool	is_valid_base(const char *base)
{
	size_t	i;
	size_t	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (false);
	i = 0;
	while (base[i] != '\0')
	{
		if ((base[i] != '-' && base[i] != '+')
			&& (base[i] < FIRST_WHITESPACE || base[i] > LAST_WHITESPACE)
			&& (base[i] != SPACE))
		{
			j = i + 1;
			while (base[j] != '\0')
			{
				if (base[i] == base[j])
					return (false);
				++j;
			}
		}
		else
			return (false);
		++i;
	}
	return (true);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	nb;
	int				sign;
	size_t			base_size;

	nb = 0;
	if (base == NULL || is_valid_base(base) == false)
		return (0);
	str = skip_whitespaces(str);
	sign = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			++sign;
		++str;
	}
	if (sign % 2 == 0)
		sign = 1;
	else
		sign = -1;
	base_size = get_rank(base, '\0');
	while (*str != '\0' && get_rank(base, *str) < base_size)
		nb = get_rank(base, *(str++)) + nb * base_size;
	return (nb * sign);
}

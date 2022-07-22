/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:20:07 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/10 23:04:12 by rbroque          ###   ########.fr       */
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

int	get_sign(const char *str)
{
	size_t	sign;

	sign = 0;
	while (*str == '+' || *str == '-')
	{
		sign += (*str == '-');
		++str;
	}
	if (sign % 2 == 1)
		return (-1);
	return (1);
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
	if (base != NULL && is_valid_base(base) == true)
	{
		str = skip_whitespaces(str);
		sign = get_sign(str);
		while (*str == '+' || *str == '-')
			++str;
		base_size = get_rank(base, '\0');
		while (*str != '\0' && get_rank(base, *str) < base_size)
		{
			nb = get_rank(base, *str) + nb * base_size;
			++str;
		}
	}
	return (nb * sign);
}

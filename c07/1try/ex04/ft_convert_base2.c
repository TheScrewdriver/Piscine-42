/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 08:33:11 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/13 18:05:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

size_t	get_rank(const char *str, const char c);
int		ft_atoi_base(char *str, char *base);
bool	is_valid_base(const char *base);
bool	is_matching_base(const char *base, const char *str);

char	*new_ft_strncpy(char *dest, char *src, unsigned int n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	size_t	i;

	i = 0;
	while (dest[i] != '\0')
		++i;
	new_ft_strncpy(dest + i, src, nb);
	return (dest);
}

void	fill_nb(char *dest, long nb, char *base, size_t size)
{
	const size_t	base_size = get_rank(base, '\0');
	long			new_nb;

	if (nb < 0)
	{
		ft_strncat(dest, "-", 1);
		new_nb = -nb;
		--size;
	}
	else
		new_nb = nb;
	if (size > 0)
	{
		fill_nb(dest, new_nb / base_size, base, size - 1);
		ft_strncat(dest, &base[new_nb % base_size], 1);
	}
}

size_t	get_size_output(int nb, const size_t base_size)
{
	unsigned int	new_nb;
	size_t			size;

	size = (nb <= 0);
	if (nb < 0)
		new_nb = -nb;
	else
		new_nb = nb;
	while (new_nb != 0)
	{
		new_nb /= base_size;
		++size;
	}
	return (size);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*output;
	int		new_nb;
	size_t	size;

	if (is_valid_base(base_from) == false || is_valid_base(base_to) == false
		|| is_matching_base(base_from, nbr) == false
		|| get_rank(nbr, '\0') == 0)
		return (NULL);
	new_nb = ft_atoi_base(nbr, base_from);
	size = get_size_output(new_nb, get_rank(base_to, '\0'));
	output = (char *)malloc((size + 1) * sizeof(char));
	if (output != NULL)
	{
		*output = '\0';
		fill_nb(output, new_nb, base_to, size);
	}
	return (output);
}

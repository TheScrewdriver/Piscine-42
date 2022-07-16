/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:08:34 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/16 19:09:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.h"

int	get_max(const int nb1, const int nb2)
{
	if (nb1 < nb2)
		return (nb2);
	return (nb1);
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

void	ft_cat(void)
{
	int		fd;
	char	buffer[1];

	fd = 0;
	while (read(fd, buffer, 1))
		ft_putchar_fd(*buffer, STDOUT_FILENO);
}

int	main(int ac, char **av)
{
	int	i;
	int	ret_value;

	i = 1;
	if (ac == 1)
		ft_cat();
	ret_value = EXIT_SUCCESS;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-") == 0)
			ft_cat();
		else
			ret_value = get_max(ft_display_file(av[i]), ret_value);
		++i;
	}
	return (ret_value);
}

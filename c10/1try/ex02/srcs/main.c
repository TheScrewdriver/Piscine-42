/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:08:34 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/21 12:33:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	print_title(char *title)
{
	ft_putstr_fd("==> ", STDOUT_FILENO);
	ft_putstr_fd(title, STDOUT_FILENO);
	ft_putstr_fd(" <==\n", STDOUT_FILENO);
}

void	print_content(const char *rest, const char *buffer)
{
	ft_putstr_fd(rest + ft_strlen(buffer), STDOUT_FILENO);
	ft_putstr_fd(buffer, STDOUT_FILENO);
}

void	ft_tail(const size_t size, const size_t fd)
{
	char	*buffer;
	char	*rest;
	ssize_t	bytes;

	buffer = (char *)malloc((size + 1) * sizeof(char));
	if (buffer != NULL)
	{
		ft_bzero(buffer, size + 1);
		rest = ft_strndup(buffer, size + 1);
		bytes = read(fd, buffer, size);
		while (bytes == (ssize_t)size)
		{
			free(rest);
			rest = ft_strndup(buffer, size);
			ft_bzero(buffer, size);
			bytes = read(fd, buffer, size);
		}
		print_content(rest, buffer);
		free(rest);
	}
	free(buffer);
	close(fd);
}

void	print_tail(const char *path_file, const size_t size)
{
	int	fd;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
		print_error(path_file);
	ft_tail(size, fd);
}

int	main(int ac, char **av)
{
	int		i;
	int		ret_value;
	int		file_number;
	size_t	size;

	i = 1;
	size = INIT_SIZE;
	ret_value = EXIT_SUCCESS;
	file_number = ac - 1;
	if (file_number == 0)
		ft_tail(size, STDIN_FILENO);
	else if (ft_strncmp(av[1], "-c", 2) == 0)
	{
		size = get_numb(av[1] + 2);
		++i;
		--file_number;
		if (size == 0 && ac > 2)
		{
			size = get_numb(av[2]);
			++i;
			--file_number;
		}
		if (size == 0)
		{
			size = INIT_SIZE;
			i = 1;
		}
	}
	while (i < ac)
	{
		if (file_number >= 2)
			print_title(av[i]);
		if (ft_strcmp(av[i], "-") == 0)
			ft_tail(size, STDIN_FILENO);
		else
			print_tail(av[i], size);
		if (ac > 2 && i < ac - 1)
			ft_putstr_fd("\n", STDOUT_FILENO);
		++i;
	}
	return (ret_value);
}

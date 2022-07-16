/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:24:10 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/16 18:54:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.h"

void	ft_putchar_fd(const char c, int fd)
{
	write(fd, &c, sizeof(char));
}

size_t	ft_strlen(const char *const str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

void	ft_putstr_fd(const char *const str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	display_content(const int fd)
{
	char	buffer[1];

	while (read(fd, buffer, 1) == 1)
		ft_putchar_fd(*buffer, STDOUT_FILENO);
}

int	ft_display_file(char *file_path)
{
	int	fd;
	int	ret_value;

	fd = open(file_path, O_RDONLY);
	ret_value = EXIT_SUCCESS;
	if (fd != -1)
		display_content(fd);
	else
	{
		ft_putstr_fd("ft_cat: ", STDERR_FILENO);
		ft_putstr_fd(file_path, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		ret_value = EXIT_FAILURE;
	}
	close(fd);
	return (ret_value);
}

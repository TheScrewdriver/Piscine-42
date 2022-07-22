/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:24:10 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/20 21:32:29 by rbroque          ###   ########.fr       */
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

void	display_content(char *file_path, const int fd)
{
	char	buffer[1];
	int		byte;

	byte = read(fd, buffer, 1);
	while (byte == 1)
	{
		ft_putchar_fd(*buffer, STDOUT_FILENO);
		byte = read(fd, buffer, 1);
	}
	if (byte == -1)
		print_error(file_path, strerror(errno));
}

int	ft_display_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd != -1)
		display_content(file_path, fd);
	else
	{
		print_error(file_path, strerror(errno));
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

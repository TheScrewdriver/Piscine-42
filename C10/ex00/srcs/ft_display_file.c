/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:24:10 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/16 13:24:08 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

void	ft_putchar(const char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
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
		ft_putchar(*buffer);
}

void	ft_display_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		ft_putstr_fd(UNREADABLE_FILE, STDERR_FILENO);
	else
		display_content(fd);
	close(fd);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:24:10 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/17 16:11:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

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

void	print_error(const char *path_file)
{
	ft_putstr_fd("ft_tail: ", STDERR_FILENO);
	ft_putstr_fd(path_file, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

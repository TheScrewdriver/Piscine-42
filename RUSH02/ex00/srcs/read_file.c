/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:10:57 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/23 23:53:38 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static ssize_t	get_size_file(const char *file_path)
{
	ssize_t	size;
	int		fd;
	char	buffer[1];

	size = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, buffer, 1) != 0)
		++size;
	close(fd);
	return (size);
}

char	*get_file(const char *file_path)
{
	const ssize_t	size = get_size_file(file_path);
	int				fd;
	char			*file;

	fd = open(file_path, O_RDONLY);
	if (fd != -1)
	{
		file = (char *)malloc((size + 1) * sizeof(char));
		if (file != NULL)
		{
			read(fd, file, size);
			file[size] = '\0';
		}
	}
	else
		file = NULL;
	close(fd);
	return (file);
}

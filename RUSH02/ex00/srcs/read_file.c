/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:10:57 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/23 09:36:16 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static size_t	get_size_file(const char *file_path)
{
	size_t	size;
	int		fd;
	char	buffer[1];

	size = 0;
	fd = open(file_path, O_RDONLY);
	while (read(fd, buffer, 1) != 0)
		++size;
	close(fd);
	return (size);
}

char	*get_file(const char *file_path)
{
	const size_t	size = get_size_file(file_path);
	int				fd;
	char			*file;

	fd = open(file_path, O_RDONLY);
	file = (char *)malloc((size + 1) * sizeof(char));
	if (file != NULL)
	{
		read(fd, file, size);
		file[size] = '\0';
	}
	return (file);
}

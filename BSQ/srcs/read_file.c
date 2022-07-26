/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:10:57 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/26 10:19:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static ssize_t	get_file_length(char *filename)
{
	int			fd;
	char		buffer[BUFFER_SIZE];
	ssize_t		bytes_read;
	ssize_t		file_length;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	file_length = 0;
	while (true)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			close(fd);
			return (-1);
		}
		file_length += bytes_read;
		if (bytes_read < BUFFER_SIZE)
		{
			close(fd);
			return (file_length);
		}
	}
}

char	*get_file(char *filename)
{
	int			fd;
	char		*str;
	ssize_t		file_length;

	file_length = get_file_length(filename);
	if (file_length == -1)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = malloc(sizeof(char) * (file_length + 1));
	if (str == NULL || read(fd, str, file_length) == -1)
	{
		close(fd);
		return (NULL);
	}
	str[file_length] = '\0';
	close(fd);
	return (str);
}

void	ft_bzero(char *array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		array[i] = 0;
		++i;
	}
}

char	*get_input(void)
{
	char	buffer[BUFFER_SIZE];
	char	*input;

	input = NULL;
	ft_bzero(buffer, BUFFER_SIZE);
	while (read(STDIN_FILENO, buffer, BUFFER_SIZE) > 0)
	{
		input = ft_stradd(&input, buffer);
		ft_bzero(buffer, BUFFER_SIZE);
	}
	return (input);
}

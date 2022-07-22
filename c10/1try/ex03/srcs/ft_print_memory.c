/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:29:36 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/21 16:23:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	print_hex(const unsigned long long nb, const size_t size)
{
	if (size > 0)
	{
		print_hex(nb / 16, size - 1);
		ft_putchar(HEX[nb % 16]);
	}
}

void	print_hex_value(void *addr, size_t offset)
{
	size_t	j;

	j = 0;
	print_hex(offset, 8);
	ft_putchar(SPACE);
	while (j < 16)
	{
		if (j % 8 == 0)
			ft_putchar(SPACE);
		print_hex(((char *)(addr))[j], 2);
		ft_putchar(SPACE);
		if (j == 15)
			ft_putchar(SPACE);
		++j;
	}
}

void	print_line(void *addr, size_t offset, bool is_same)
{
	size_t	j;
	char	c;

	j = 0;
	if (is_same == true)
		ft_putchar('*');
	else
	{	
		print_hex_value(addr, offset);
		ft_putchar(PIPE);
		while (j < 16)
		{
			c = ((char *)(addr))[j];
			if (c >= FIRST_PRINTABLE && c <= LAST_PRINTABLE)
				ft_putchar(c);
			else
				ft_putchar(DOT);
			++j;
		}
		ft_putchar(PIPE);
	}
	ft_putchar('\n');
}

void	ft_bzero(char *array, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		array[i] = '\0';
		++i;
	}
}

void	ft_print_memory(const char *file_path)
{
	size_t	i;
	int		fd;
	bool	is_same;
	char	prev_buff[BUFF_SIZE];
	char	buffer[BUFF_SIZE];

	i = 0;
	fd = open(file_path, O_RDONLY);
	ft_bzero(buffer, BUFF_SIZE);
	is_same = false;
	while (read(fd, buffer, BUFF_SIZE - 1) != 0)
	{
		if (ft_strcmp(prev_buff, buffer) == 0)
			is_same = true;
		else
			is_same = false;
		print_line(buffer, i * 16, is_same);
		ft_strncpy(prev_buff, buffer, BUFF_SIZE);
		ft_bzero(buffer, BUFF_SIZE);
		++i;
	}
	close(fd);
}

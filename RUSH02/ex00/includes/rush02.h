/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:00:02 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/23 17:54:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <errno.h>

# define SPACE ' '
# define SEPARATOR ':'
# define ERROR_MESSAGE "Dict Error\n"
# define FIRST_WHITESPACE 9
# define LAST_WHITESPACE 13

typedef struct s_map
{
	unsigned int	key;
	char			*value;
}			t_map;

// READ_FILE.C

char	*get_file(const char *file_path);

// FT_SPLIT.C

char	**ft_split(char *str, char *charset);

// FREE.C

void	free_strings(char **strs);

// LEXER.C

bool	is_valid_line(const char *str);

// PARSING.C

char	*ft_create_value(char *str);

// STRING.C

size_t	ft_strlen(const char *str);
char	*ft_strncpy(char *dest, char *src, size_t n);

// MAP.C

t_map	create_map(char *line);
t_map	init_map(unsigned int input_key, char *input_value);

// FT_ATOI.C

int	ft_atoi(char *str);

#endif

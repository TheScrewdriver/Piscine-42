/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:00:02 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/23 16:49:14 by rbroque          ###   ########.fr       */
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

typedef struct s_map
{
	char	*key;
	char	*value;
}			t_map;

// READ_FILE.C

char	*get_file(const char *file_path);

// FT_SPLIT.C

char	**ft_split(char *str, char *charset);

// FREE.C

void	free_strings(char **strs);

// PARSER.C

bool	is_valid_line(const char *str);

#endif

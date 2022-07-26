/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:02:01 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/26 14:02:01 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFFER_SIZE 8192
# define FIRST_WHITESPACE 9
# define LAST_WHITESPACE 13
# define SPACE ' '
# define FIRST_PRINTABLE 32
# define LAST_PRINTABLE 126
# define MAP_ERROR "map error\n"

typedef struct s_bsq
{
	size_t	x;
	size_t	y;
	size_t	size;
}				t_bsq;

typedef struct s_map
{
	char	**grid;
	size_t	**matrix;
	size_t	height;
	size_t	width;
	char	empty;
	char	obstacle;
	char	full;
}				t_map;

// DISPLAY.C
void	display_map(t_map map, t_bsq bsq);

// ERROR.C
int		handle_error(bool is_error, int ret_value);

// FT_SPLIT.C
char	**ft_split_lines(char *str);

// FT_STRADD.C
char	*ft_stradd(char **dest, char *src);

// FREE.C
void	free_matrix(size_t **matrix, size_t size);
void	free_lines(char **lines);

// MAP.C
t_map	create_map(char **lines);

// MATH.C
size_t	min_of_three(size_t n1, size_t n2, size_t n3);
size_t	get_nb_size(int nb);
int		ft_atoi(char *str);

// PARSING.C
bool	is_valid_map(char **lines);

// READ_FILE.C
char	*get_file(char *file_path);
char	*get_input(void);

// SOLVE.C
t_bsq	solve(t_map map);

// STRINGS.C
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(const char *str, const int fd);
void	ft_putchar(const char c);
char	*ft_strchr(char *str, char c);
char	*ft_strncpy(char *dest, char *src, size_t n);

#endif

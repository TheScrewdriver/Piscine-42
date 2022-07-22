/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:21:51 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/17 17:59:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAIL_H

# define TAIL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/stat.h>
# include <errno.h>
# include <stdbool.h>

# define FIRST_WHITESPACE 9
# define LAST_WHITESPACE 13
# define SPACE ' '
# define INIT_SIZE 10

void	ft_putstr_fd(const char *const str, int fd);
void	ft_putchar_fd(const char c, int fd);
void	print_error(const char *path_file);

size_t	ft_strlen(const char *const str);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strndup(char *str, const size_t n);
int		ft_strcmp(char *s1, char *s2);
void	ft_bzero(char *str, const size_t size);

int	get_numb(const char *av);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:47:08 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/21 14:53:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <errno.h>

#define FIRST_PRINTABLE 32
#define LAST_PRINTABLE 126
#define HEX "0123456789abcdef"
#define SEPARATOR ':'
#define DOT '.'
#define SPACE ' '
#define BUFF_SIZE 17
#define PIPE '|'

void	ft_print_memory(const char *file_path);

char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strcmp(char *s1, char *s2);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:24:21 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/16 13:25:16 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_FILE_H

# define FT_DISPLAY_FILE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>

# define BUFFER_SIZE 1
# define MISSING_FILE "File name missing.\n"
# define TOO_MANY_FILES "Too many arguments.\n"
# define UNREADABLE_FILE "Cannot read file.\n"
# define EXPECTED_ARG 2

void	ft_putstr_fd(const char *const str, int fd);
void	display_content(const int fd);
void	ft_display_file(char *file_path);

#endif

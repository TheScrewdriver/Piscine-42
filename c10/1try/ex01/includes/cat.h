/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:07:48 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/20 13:44:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H

# define CAT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <errno.h>

int		ft_display_file(char *file_path);
void	ft_putchar_fd(const char c, int fd);
void	ft_putstr_fd(const char *const str, int fd);

void	print_error(char *path_file, char *error);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:33:53 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/20 13:43:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.h"

void	print_error(char *file_path, char *error)
{
	ft_putstr_fd("ft_cat: ", STDERR_FILENO);
	ft_putstr_fd(file_path, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

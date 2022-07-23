/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:27:33 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/23 19:27:35 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putchar(const char c)
{
	write(STDOUT_FILENO, &c, sizeof(c));
}

void	ft_putstr(const char *str)
{
	if (str != NULL)
		write(STDOUT_FILENO, str, ft_strlen(str));
}

void	display_error(void)
{
	ft_putstr(ERROR_MESSAGE);
}

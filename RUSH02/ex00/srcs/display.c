/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:15:29 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/23 16:22:15 by rbroque          ###   ########.fr       */
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

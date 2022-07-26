/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:48:25 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/25 20:50:18 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	handle_error(bool is_error, int ret_value)
{
	if (is_error == true)
		ft_putstr_fd(MAP_ERROR, STDERR_FILENO);
	return (ret_value || is_error);
}

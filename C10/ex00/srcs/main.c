/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:23:19 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/16 13:24:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

int	main(int ac, char **av)
{
	if (ac < EXPECTED_ARG)
		ft_putstr_fd(MISSING_FILE, STDERR_FILENO);
	else if (ac > EXPECTED_ARG)
		ft_putstr_fd(TOO_MANY_FILES, STDERR_FILENO);
	else
		ft_display_file(av[1]);
	return (EXIT_SUCCESS);
}

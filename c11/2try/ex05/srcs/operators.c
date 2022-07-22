/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:44:33 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/17 21:51:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

long	add(const int nb1, const int nb2)
{
	return (nb1 + nb2);
}

long	sub(const int nb1, const int nb2)
{
	return (nb1 - nb2);
}

long	mult(const int nb1, const int nb2)
{
	return (nb1 * nb2);
}

long	division(const int nb1, const int nb2)
{
	return (nb1 / nb2);
}

long	mod(const int nb1, const int nb2)
{
	return (nb1 % nb2);
}

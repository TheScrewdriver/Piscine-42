/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:50:46 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/17 21:50:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H

# define DO_OP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define FIRST_WHITESPACE 9
# define LAST_WHITESPACE 13
# define SPACE ' '
# define DIVISION_ZERO "Stop : division by zero"
# define MOD_ZERO "Stop : modulo by zero"

void	ft_putnbr(long nb);
int		ft_atoi(char *str);

long	add(const int nb1, const int nb2);
long	sub(const int nb1, const int nb2);
long	mult(const int nb1, const int nb2);
long	division(const int nb1, const int nb2);
long	mod(const int nb1, const int nb2);

int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(const char *const str);
void	ft_putchar(const char c);

#endif

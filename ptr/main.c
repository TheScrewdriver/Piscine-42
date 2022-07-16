/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:11:48 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/09 18:17:58 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	printf("addresse de a -- > %p\n", a);
	printf("valeur de a -- > %d\n", *a);

	printf("addresse de b -- > %p\n", b);
	printf("valeur de b -- > %d\n", *b);

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(void)
{
	int	c;
	int	d;

	c = 42;
	d = 0;
	ft_swap(&c, &d);
	printf("addresse de a -- > %p\n", &c);
	printf("valeur de a -- > %d\n", c);

	printf("addresse de b -- > %p\n", &d);
	printf("valeur de b -- > %d\n", d);
}

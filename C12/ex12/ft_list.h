/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:43:41 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/19 12:56:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H

# define FT_LIST_H

# include <stdlib.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
						void (*free_fct)(void *));
#endif

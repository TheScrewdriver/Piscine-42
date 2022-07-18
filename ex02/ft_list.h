/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:09:41 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/18 17:29:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H

# define FT_LIST_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

#endif

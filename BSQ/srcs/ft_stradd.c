/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:24:53 by rbroque           #+#    #+#             */
/*   Updated: 2022/07/26 10:18:38 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strdup(char *str)
{
	const size_t	size = ft_strlen(str);
	char			*new;

	new = (char *)malloc((size + 1) * sizeof(char));
	if (new != NULL)
	{
		ft_strncpy(new, str, size);
		new[size] = '\0';
	}
	return (new);
}

char	*ft_stradd(char **dest, char *src)
{
	char	*tmp;
	size_t	size1;
	size_t	size2;

	if (src == NULL)
		return (*dest);
	if (*dest == NULL)
		return (ft_strdup(src));
	size1 = ft_strlen(*dest);
	size2 = ft_strlen(src);
	tmp = *dest;
	*dest = (char *)malloc((size1 + size2 + 1) * sizeof(char));
	if (*dest != NULL)
	{
		ft_strncpy(*dest, tmp, size1);
		ft_strncpy(*dest + size1, src, size2);
		(*dest)[size1 + size2] = '\0';
	}
	free(tmp);
	return (*dest);
}

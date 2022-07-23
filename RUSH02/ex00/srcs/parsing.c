/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-garr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:27:24 by ale-garr          #+#    #+#             */
/*   Updated: 2022/07/23 16:34:54 by ale-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

size_t	ft_first_space(char *str)
{
	size_t	i;
	
	i = 0;
	while (str[i] == 32)
		i++;
	return (i);
}

size_t     ft_strlen(char *str)
{
        size_t     i;

        i = 0;
        while (str[i] != '\0')
        {
        i++;
        }
	return (i);
}

size_t	ft_last_space(char *str)
{
	size_t	size;
	size_t	j;

	size = ft_strlen(str);
	j = 0;
        while (j < size && str[size - 1 - j] == 32)
		j++;
	return (j);
}

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_create_value(char *str)
{
	const size_t	first_spaces = ft_first_space(str);
	const size_t	new_size = ft_strlen(str) - (first_spaces + ft_last_space(str));
	char		*value;

        value = (char *)malloc(sizeof(char) * (new_size + 1));
        if (value == NULL)
        {
                return(value);
        }
        ft_strncpy(value, str + first_spaces, new_size);
        value[new_size] = '\0';
        return(value);
}

int     main()
{
	char	*value;

        value = ft_create_value("          any_printable     characters        ");
	//printf("%s\n", key);
	printf("%s\n", value);
        return(0);
}

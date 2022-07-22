
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(char *str)
{
	char	*new;

	new = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (new != NULL)
	{
		dostuff...
	}
	return (new);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		ft_putnbr(atoi(av[1]));
	return (0);
}

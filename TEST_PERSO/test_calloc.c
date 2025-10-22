
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;
	size_t	i;

	i = 0;
	tab = malloc(count * size);			//si zone memoire a 0 comme valeur
	if (!tab)
		return (NULL);
	while (i < count * size)			//la zone memoire c'est pas juste size, ca peut etre plus d'octet en fonction du type et faut tout rewmplir
	{
		((unsigned char *)tab)[i] = 0;
		i++;
	}
	return (tab);
}

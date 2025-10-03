
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char *s2;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	s2 = malloc((i + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int main (void)
{
	const char *origin = "hello worldpspal";
	char *dest;

	dest = ft_strdup(origin);

	printf("%s\n", dest);
	free (dest);
}


#include <stdio.h>
#include <string.h>


char *ft_strchr(const char *s, int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	if (*s == '\0')
		return ((char *)s);
	while (*s)
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}

int main (void)
{
	char *str = "hdeaicdhia";
	char c = 'c';

	printf("%s\n", ft_strchr(str, c));
	printf("%s\n", strchr(str, c));
}
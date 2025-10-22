
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	if (*s == '\0')
		return ((char *)s);
	while (*s)
		s++;
	while (*s >= 0)
	{
		if (*s == a)
		{
			return ((char *)s);
		}
		s--;
	}
	return (NULL);
}

#include <string.h>


int main (void)
{
	char *str = "helloworld helloworld";
	char c = 'h';
	printf("%s\n", ft_strrchr(str, c));

	printf("%s", strrchr(str, c));
}
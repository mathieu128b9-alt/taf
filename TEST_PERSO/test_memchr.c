
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	size_t i;

	i = 0;
	a = (unsigned char)c;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (((unsigned char *)s)[i] == a)
		{
			return (void *) ((unsigned char *)s + i);
		}
		i++;
	}
	return (NULL);
}

int main (void)
{
	char *str = "helloworld";
	char c = 'l';
	size_t n = 4;

	printf("%p\n", ft_memchr(str, c, n));

	printf("%p\n", memchr(str, c, n));
}

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char i;

	i = 0;
	while (s1[i] && s2[i] && n != 0 && (s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int main (void)
{
	char *s1 = "hlloworld";
	char *s2 = "helloworld";
	printf("%d\n", ft_strncmp(s1, s2, 5));

	printf("%d\n", strncmp(s1, s2, 5));
}
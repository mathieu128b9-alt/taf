
#include <stdio.h>
#include <string.h>


int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;
	size_t i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] == str2[i]) && str1[i] && str2[i] && i < n - 1)
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

int main (void)
{
	char *t1 = "hello world";
	char *t2 = "eo world";
	size_t n = 3;

	printf("%d\n", ft_memcmp(t1, t2, n));
	printf("%d\n", memcmp(t1, t2, n));

}
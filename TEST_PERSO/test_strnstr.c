
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;

	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len && little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

int main (void)
{
	const char *big = "hello world";
	const char *little = "rld";
	size_t n = 20;

	printf("%s\n", ft_strnstr(big, little, n));


	printf("%s\n", strnstr(big, little, n));


}
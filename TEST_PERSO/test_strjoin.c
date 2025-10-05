#include <stdlib.h>
#include <stdio.h>

void ft_strcpy(char *dest, char const *src1, char const *src2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src1[i])
	{
		dest[i] = src1[i];
		i ++;
	}
	while (src2[j])
	{
		dest[i + j] = src2[j];
		j++;
	}
	dest[i + j] = '\0';
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	size_t	i;

	i = ft_strlen(s1) + ft_strlen(s2);
	final = malloc((i + 1) * sizeof(char));
	if (!final)
		return (NULL);
	ft_strcpy(final, s1, s2);
	return (final);
}

int main (void)
{
	char *s1 = "hello ";
	char *s2 = "world";
	char *res =ft_strjoin(s1, s2);
	printf("%s", res);
	free (res);
}
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	count_tronc(const char *s1, const char *set, size_t *debut, size_t *fin)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[i])
	{
		if (set[i] == s1[j] && s1[j] != '\0')
		{
			i = 0;
			j++;
			(*debut)++;
			continue;
		}
		i++;
	}
	i = 0;
	j = ft_strlen(s1);
	while (set[i])
	{
		if (j > *debut && set[i] == s1[j - 1])
		{
			i = 0;
			j--;
			(*fin)--;
			continue;
		}
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char *final;
	size_t	debut;
	size_t	fin;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	debut = 0;
	i = 0;
	fin = ft_strlen(s1);
	count_tronc(s1, set, &debut, &fin);
	if (fin >= debut)
		j = fin - debut;
	else
	{
		final = malloc(sizeof(char) * 1);
		final[0] = '\0';
		return (final);
	}

	final = malloc((j + 1) * sizeof(char));
	if (!final)
		return (NULL);
	while (debut < fin)
	{
		final[i] = s1[debut];
		i++;
		debut++;
	}
	final[i] = '\0';
	return (final);
}

int main (void)
{
	const char *s1 = NULL;;
	const char *set = "i";
	char *test;
	test = ft_strtrim(s1, set);
	printf("%s", test);
	free (test);

}
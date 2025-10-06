
#include <stdlib.h>
#include <stdio.h>


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && size > 1)
	{
		dest[i] = src[i];
		i++;
		size--;
	}
	if (size != 0)
		dest[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}


int	mot(const char *chaine, char c)
{
	size_t	i;
	size_t	nbmot;

	if (!chaine)
		return (0);
	i = 0;
	nbmot = 0;
	while (chaine[i])
	{
		while (chaine[i] == c)
			i++;
		if (!chaine[i])//cas ou separat a la fin
			break ;
		nbmot++;
		while (chaine[i] && chaine[i] != c)
			i++;
	}
	return (nbmot);
}

char	**ft_split(char const *s, char c)
{
	char **final;
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	start;

	i = 0;
	j = 0;
	final = malloc(sizeof(char *) * (mot(s, c) + 1));
	if (!final)
		return (NULL);
	while (s[i])
	{
		len = 0;
		while (s[i] == c)
			i++;
		if(s[i] == '\0')
			break;
		start = i;
		while ( s[i] && s[i] != c)
			i++;
		len = i - start;
		final[j] = malloc(sizeof(char) * (len + 1));
		if (!final[j])
			return (NULL);
		ft_strlcpy(final[j], s + start, (len + 1));
		j++;
	}
	return (final);
}

int main (void)
{
	const char *tab = "    f     ";
	char sep = ' ';
	char **fin = ft_split(tab, sep);
	size_t	i = 0;
	while (fin[i] != NULL)
	{
		printf("%s\n", fin[i]);
		i++;
	}
}

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

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


char	*ft_substr(char const *s, unsigned int start, size_t len) /*copie d'une sous chaine, commence au start element et fait len copies*/
{
	size_t	i;
	char	*str;

	i = ft_strlen((char *)s);
	if (start >= i) /*copie uniquement un \0, (rien a copier apres une fin de chaine)*/
	{
		str = malloc (1 * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	else if (len > i - start)
	{
		len = (i - start);
		str = malloc ((len + 1) * sizeof(char));
		if (!str)
			return (NULL);
		ft_strlcpy(str, (s + start), (len + 1));
		return (str);
	}
	else
	{
		str = malloc ((len + 1) * sizeof(char));
		if(!str)
			return (NULL);
		ft_strlcpy(str, (s + start), (len + 1));
		return (str);
	}
}

int main (void)
{
	const char *st = "hello world";
	unsigned int i = 2;
	size_t len = 5;
	printf("%s", ft_substr(st, i, len));
}

#include <stdio.h>


int	ft_tolower(int c)
{
	if ((c + 32) >= 97 && (c + 32) <= 122)
		return (c + 32);
	return (c);
}

int main (void)
{
	char c1 = 'A';
	char c2 = 'Z';
	char c3 = ']';
	char c4 = '=';

	printf("%c\n", ft_tolower(c1));
	printf("%c\n", ft_tolower(c2));
	printf("%c\n", ft_tolower(c3));
	printf("%c\n", ft_tolower(c4));
}
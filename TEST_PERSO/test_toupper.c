
#include <stdio.h>
#include <ctype.h>

int	ft_toupper(int c)
{
	if ((c - 32) >= 65 && (c - 32) <= 90)
		return (c - 32);
	return (c);
}

int main (void)
{
	char c1 = 'a';
	char c2 = '@';
	char c3 = ']';
	char c4 = '=';

	printf("%c\n", ft_toupper(c1));
	printf("%c\n", ft_toupper(c2));
	printf("%c\n", ft_toupper(c3));
	printf("%c\n", ft_toupper(c4));
}
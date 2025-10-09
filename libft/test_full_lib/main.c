
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
	/*printf("%d\n", ft_atoi("380129"));			//ft_atoi
	printf("%d\n", ft_atoi("-317298"));
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", ft_atoi("842384320848484"));
	printf("%d\n", ft_atoi("dwhdh"));
	printf("%d\n", ft_atoi("  	3182"));
	printf("%d\n", ft_atoi(" 3182"));
	printf("%d\n", atoi("3801aaa29"));
	printf("\n%d\n", atoi("380129"));
	printf("%d\n", atoi("-317298"));
	printf("%d\n", atoi("0"));
	printf("%d\n", atoi("842384320848484"));
	printf("%d\n", atoi("dwhdh"));
	printf("%d\n", atoi("  	3182"));
	printf("%d\n", atoi(" 3182"));
	printf("%d", atoi("3801aaa29"));*/


	/*char tab[10] = "123456789";			//ft_bzero
	ft_bzero(tab, 5);
	int i = 0;
	while (i < 10)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	printf("%s", "\n");
	char tab1[10] = "123456789";
	bzero(tab1, 5);
	int j = 0;
	while (j < 10)
	{
		printf("%d\n", tab1[j]);
		j++;
	}*/


	/*size_t i = 38;					//ft_calloc
	int j = 0;
	int k = 0;
	int *b =ft_calloc(i, sizeof(int));
	int *a =calloc(i, sizeof(int));

	if (!a || !b)
	{
		printf("%s\n", "erreur");
		return (0);
	}
	while (j < 38)
	{
		printf("%d", a[j]);
		j++;
	}
	printf("%s", "\n");
	while (k < 38)
	{
		printf("%d", a[k]);
		k++;
	}*/


	/*printf("%d\n", ft_isalnum('/'));			//ft_isalnum
	printf("%d\n", ft_isalnum('s'));
	printf("%d\n", ft_isalnum('9'));
	printf("%d\n", ft_isalnum('A'));

	printf("%s", "\n");
	printf("%d\n", isalnum('/'));
	printf("%d\n", isalnum('s'));
	printf("%d\n", isalnum('9'));
	printf("%d\n", isalnum('A'));*/


	/*printf("%d\n", ft_isalpha('s'));		//ft_isalpha
	printf("%d\n", ft_isalpha('P'));
	printf("%d\n", ft_isalpha(';'));
	printf("%s", "\n");
	printf("%d\n", isalpha('s'));
	printf("%d\n", isalpha('P'));
	printf("%d\n", isalpha(';'));*/


	/*printf("%d\n", ft_isascii('a'));			//ft_isascii
	printf("%d\n", ft_isascii('Z'));
	printf("%d\n", ft_isascii(' '));
	printf("%d\n", ft_isascii(230));
	printf("%s", "\n");
	printf("%d\n", isascii('a'));
	printf("%d\n", isascii('Z'));
	printf("%d\n", isascii(' '));
	printf("%d\n", isascii(230));*/


	/*printf("%d\n", ft_isdigit('1'));			//ft_isdigit
	printf("%d\n", ft_isdigit('9'));
	printf("%d\n", ft_isdigit('0'));
	printf("%d\n", ft_isdigit('a'));
	printf("%s", "\n");
	printf("%d\n", isdigit('1'));
	printf("%d\n", isdigit('9'));
	printf("%d\n", isdigit('0'));
	printf("%d\n", isdigit('a'));*/


	/*printf("%d\n", ft_isprint('a'));			//ft_isprint
	printf("%d\n", ft_isprint(2));
	printf("%d\n", ft_isprint(120));
	printf("%d\n", ft_isprint('9'));
	printf("%s", "\n");
	printf("%d\n", isprint('a'));
	printf("%d\n", isprint(2));
	printf("%d\n", isprint(120));
	printf("%d\n", isprint('9'));*/


	/*printf("%s\n", ft_itoa(381321));		ft_itoa
	printf("%s\n", ft_itoa(-41384330));
	printf("%s\n", ft_itoa(0));*/



	/*char *s = "hellooooworld";			ft_memchr
	int c = 'l';
	size_t n = 13;
	int i = 0;

	char *final = ft_memchr(s, c, n);
	while (final[i])
	{
		printf("%c", final[i]);
		i++;
	}
	printf("%s", "\n");
	int j = 0;
	char *final1 = memchr(s, c, n);
	while (final1[j])
	{
		printf("%c", final[j]);
		j++;
	}*/


	/*char *s1 = "hello world";				ft_memcmp
	char *s2 = "hello world";

	char *str1 = "hhhhhhhheeeeeeelllllo";
	char *str2 = "hhhhhhhheeeeeeelllll";

	char *st1 = "hhhhhhhheeeeeeelllll";
	char *st2 = "hhhhhhhheeeeeeelllllo";
	
	printf("%d\n", ft_memcmp(s1, s2, 10));
	printf("%d\n", memcmp(s1, s2, 10));

	printf("%d\n", ft_memcmp(str1, str2, 21));
	printf("%d\n", memcmp(str1, str2, 21));

	printf("%d\n", ft_memcmp(st1, st2, 21));
	printf("%d\n", memcmp(st1, st2, 21));*/


	char *src1 = "hello world";
	char dest[3];
	size_t n = 0;
	char *res = ft_memcpy(dest, src1, n);
	printf("%s\n", res);

	char *res1 = memcpy(dest, src1, n);
	printf("%s\n", res1);
}

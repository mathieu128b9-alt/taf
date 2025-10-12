
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <string.h>



	/*void test(unsigned int i, char *c)			//ft_striteri
	{
		
		if (*c >= 'a' && *c <= 'z')
			*c = *c - 32;
		(void)i;
	}*/

	char test(unsigned int i, char c)
	{
		(void)i;
		if (c >= 'a' && c <= 'z')
			return (c -32);
		return (c);
	}

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


	/*char *s1 = "hello world";				//ft_memcmp
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


	/*char *src1 = "hello world";			//ft_memcpy
	char dest[10];
	size_t n = 4;
	char *res = ft_memcpy(dest, src1, n);
	printf("%s\n", res);

	char *res1 = memcpy(dest, src1, n);
	printf("%s\n", res1);*/

													//ft_memmove

	//cas avant, je veux copier ma source +2 (10 char), a dans ma dest +12, (pas de chevauchement, les donnees sont toutes conservees)
	//cas arriere, je veux copier ma source + 2 (10char), dans ma dest +3, (les chaines se chevauchent, les donnes seront perdues, donc en arriere)
	/*char tab[] = "memmove un exemple concret, j'essaie de compendre quand ca copie en avant ou en arriere";
	char tab2[] = "memmove un exemple concret, j'essaie de compendre quand ca copie en avant ou en arriere";

	char *res1 = ft_memmove(tab + 12, tab + 2, 10);
	printf("%s\n", res1);

	char *res2 = memmove(tab2 + 12, tab2 + 2, 10);
	printf("%s\n", res2);*/


	/*char str[50] = "helloworlllllld";				//ft_memset
	int c = 'b';
	char *modif = ft_memset(str, c, 13);
	printf("%s\n", modif);
	char str2[50] = "helloworlllllld";
		char *modif2 = memset(str2, c, 13);
	printf("%s\n", modif2);*/


	/*ft_putnbr_fd(3245635, 1);				//ft_putnbr_fd
	printf("%s", "\n");
	ft_putnbr_fd(-573489, 1);
	printf("%s", "\n");
	ft_putnbr_fd(0, 1);*/

	/*char *tab = "bonjour , je test ma fonction split";		//ft_split
	char c = ' ';
	char **final = ft_split(tab, c);
	int i = 0;
	while (final[i])
	{
		printf("%s", final[i]);
		printf("%s", "\n");
		i++;
	}*/


	/*int c = 'z';							//ft_strchr
	char str[] = "hello warld";

	printf("%s\n", ft_strchr(str, c));
	printf("%s", strchr(str, c));*/

	/*char *s1 = "hello world";				//ft_strdup
	char *s2 = "";
	printf("%s\n", ft_strdup(s1));
	printf("%s\n", ft_strdup(s2));
	printf("%s\n", strdup(s1));
	printf("%s\n", strdup(s2));*/
	
	
	/*char s1[] = "hello world";			//ft_striteri
	printf("%s\n", s1);
	ft_striteri(s1, test);
	printf("%s\n", s1);*/



	/*char *debut = "hello ";				//ft_strjoin
	char *fin = "world";
	char *res1 = ft_strjoin(debut, fin);
	printf("%s", res1);*/

	/*char *src = "hello world";			//ft_strlcat
	char dest[15] = "test strlcat";
	char dest2[15] = "test strlcat";

	ft_strlcat(dest, src, sizeof(dest));
	printf("%s\n", dest);
	strlcat(dest2, src, sizeof(dest2));
	printf("%s\n", dest2);*/


	/*char *debut = "fhwiehfiwnhfiwjwofjoewjd";		//ft_strlcpy
	char fin[10] = "world";
	char fin2[10] = "world";

	ft_strlcpy(fin, debut, sizeof(fin));
	printf("%s\n", fin);
	strlcpy(fin2, debut, sizeof(fin2));
	printf("%s\n", fin2);*/


	/*const char *s1 = "hello world";			//ft_strmapi
	printf("%s", ft_strmapi(s1, test));*/


	/*char *s1 = "hllo world";					//ft_strncmp
	char *s2 = "hello world";
	printf("%d\n", ft_strncmp(s1, s2, 2));
	printf("%d\n", strncmp(s1, s2, 2));*/


	/*char *princip = "a la recherche d'un mot dans une chaine de char";;		//ft_strnstr
	char *cherche = "ans";
	printf("%s\n", ft_strnstr(princip, cherche, 50));
	printf("%s\n", strnstr(princip, cherche, 50));*/


	/*const char *s1 = "hello worlddhniwenc";			//ft_strrchr
	char c = 'z';
	printf("%s\n", ft_strrchr(s1, c));
	printf("%s\n", strrchr(s1, c));*/


	/*const char *big = "abccabcbcbahelloabca worldabcabcbbcac";		ft_strtrim
	const char *trim = "abc";
	printf("%s\n", ft_strtrim(big, trim));*/


	/*const char *s1 = "test de ma fontion substr, /.4324";			ft_substr
	unsigned int i = 15;
	size_t j = 5;
	printf("%s\n", ft_substr(s1, i, j));*/


	
}

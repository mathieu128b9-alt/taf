#include <string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	taille;

	j = 0;
	i = 0;
	taille = 0;
	while (dst[i])
	{
		i++;
	}
	taille = i;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	j = 0;
	while (src[j])
		j++;
	return (taille + j);
	
}

int main(void)
{
	char dst[7] = "hello";
	const char src[] = "world";
	size_t taille_max = sizeof(dst);

	printf("%zu\n", ft_strlcat(dst, src, taille_max));
	printf("%s\n", dst);
	
	/*char dst1[7] = "hello";
	char src1[] = "world";
	
	printf("%zu\n", strlcat(dst1, src1, taille_max));
	printf("%s\n", dst1);*/
}
#include <stdio.h>
#include <stdlib.h>

int is_negatif(char t, int negat)
{
	if (t == '+')
		return (negat);
	else if (t == '-')
		return (-negat);
	else
		return (negat);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	total;

	i = 0;
	sign = 1;
	total = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = is_negatif(str[i], sign);
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10;
		total = total + (str[i] - '0');
		i++;
	}
	return (total * sign);
}

int main (void)
{
	char *str = "    			-243729";

	printf("%d\n", ft_atoi(str));

	printf("%d\n", atoi(str));
}
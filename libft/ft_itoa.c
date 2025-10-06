/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:35:28 by msuter            #+#    #+#             */
/*   Updated: 2025/10/06 18:00:11 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(int n)
{
	int	i;
	int	comp;

	i = 0;
	comp = n;
	if (n < 0)
	{
		comp = -comp;
		i++;
	}
	while (comp >= 10)
	{
		comp = comp / 10;
		i++;
	}
	return (i + 1);
}

int	reverse_sign(int n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
}

char	*algo(int n, char *tab, int placement)
{
	placement = count(n);
	if (n < 0)
		n = -n;
	tab[placement] = '\0';
	placement--;
	while (n >= 10)
	{
		tab[placement] = (n % 10) + '0';
		n = n / 10;
		placement--;
	}
	tab[placement] = n + '0';
	return (tab);
}

char	*ft_itoa(int n) // convertir in int en char *, (inverse de atoi)
{
	char	*number;
	int		placement;

	placement = 0;
	number = malloc(sizeof(char) * (count(n) + 1));
	if (!number)
		return (NULL);
	if (reverse_sign(n) == -1)
	{
		number[placement] = '-';
		placement++;
	}
	algo(n, number, placement);
	return (number);
}

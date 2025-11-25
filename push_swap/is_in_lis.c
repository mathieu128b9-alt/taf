/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_lis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:03:14 by msuter            #+#    #+#             */
/*   Updated: 2025/11/25 12:48:16 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	value_in_lis(int value, int *lis, int size_lis)
{
	int	j;

	j = 0;
	while (j < size_lis)
	{
		if (value == lis[j])
			return (1);
		j++;
	}
	return (0);
}

void	is_in_lis(int *tab_a, int *size_a, int *tab_b, int *size_b)
{
	int	*lis;
	int	size_lis;
	int	orig_size;
	int	i;
	int	in_lis;

	lis = NULL;
	size_lis = new_lis(tab_a, *size_a, &lis);
	if (!lis)
		return ;
	orig_size = *size_a;
	i = 0;
	while (i < orig_size)
	{
		in_lis = value_in_lis(tab_a[0], lis, size_lis);
		if (in_lis)
			rotate_a(tab_a, size_a);
		else
			push_b(tab_a, size_a, tab_b, size_b);
		i++;
	}
	free(lis);
}

int	min_max(long res)
{
	if (res >= 2147483647 && res <= -2147483648)
		return (0);
	return (1);
}

int	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	total;

	i = 0;
	sign = 1;
	total = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + (str[i] - '0');
		i++;
	}
	return (total * sign);
}

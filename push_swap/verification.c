/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 08:25:45 by msuter            #+#    #+#             */
/*   Updated: 2025/12/19 13:00:00 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	verif_double(int *tab_a, int size_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_a)
	{
		j = i + 1;
		while (j < size_a)
		{
			if (tab_a[i] == tab_a[j])
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	free_all(int *tab_a, int *tab_b)
{
	free(tab_a);
	free(tab_b);
	return (1);
}

int	min_max(long res)
{
	if (res < (long)INT_MIN || res > (long)INT_MAX)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

int	valid_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (!argv[i][j])
			return (ft_putstr_fd("Error\n", 2), 1);
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (!argv[i][j])
			return (ft_putstr_fd("Error\n", 2), 1);
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (ft_putstr_fd("Error\n", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}

long	ft_atol(const char *str)
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

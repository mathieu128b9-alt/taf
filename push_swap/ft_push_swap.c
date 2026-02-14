/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:56:14 by msuter            #+#    #+#             */
/*   Updated: 2026/02/14 15:43:15 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	already_sorted(int *tab_a, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a - 1)
	{
		if (tab_a[i] > tab_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	convert_to_int(int argc, char **argv, int *tab_a)
{
	int		i;
	int		j;
	long	temp;

	i = 1;
	j = 0;
	while (i < argc)
	{
		temp = ft_atol(argv[i]);
		if (min_max(temp) == 1)
			return (1);
		tab_a[j] = temp;
		i++;
		j++;
	}
	return (0);
}

void	reorganise_order_tab_a(int *tab_a, int size_a)
{
	int	indice;
	int	i;

	i = 0;
	indice = 0;
	while (i < size_a)
	{
		if (tab_a[i] < tab_a[indice])
			indice = i;
		i++;
	}
	i = size_a - indice;
	if (indice > size_a / 2)
		while (i-- > 0)
			rotate_reverse_a(tab_a, &size_a);
	else
		while (indice-- > 0)
			rotate_a(tab_a, &size_a);
}

static void	verif_mall(int *tab_a, int *tab_b)
{
	if (!tab_a && tab_b)
	{
		free (tab_b);
		exit(1);
	}
	else if (!tab_b && tab_a)
	{
		free (tab_a);
		exit(1);
	}
	else if (!tab_a && !tab_b)
	{
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int	*tab_a;
	int	*tab_b;
	int	size_b;
	int	size_a;

	size_a = argc - 1;
	tab_a = malloc(sizeof(int) * size_a);
	size_b = 0;
	tab_b = malloc(sizeof(int) * size_a);
	verif_mall(tab_a, tab_b);
	if (valid_number(argc, argv) == 1)
		return (free_all(tab_a, tab_b));
	if (convert_to_int(argc, argv, tab_a) == 1)
		return (free_all(tab_a, tab_b));
	if (verif_double(tab_a, size_a) == 1)
		return (free_all(tab_a, tab_b));
	if (already_sorted(tab_a, size_a) == 1)
		return (free_all(tab_a, tab_b));
	sort_stack(tab_a, tab_b, &size_a, &size_b);
	free(tab_a);
	free(tab_b);
}

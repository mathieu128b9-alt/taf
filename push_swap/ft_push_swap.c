/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:56:14 by msuter            #+#    #+#             */
/*   Updated: 2025/11/23 14:05:03 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	convert_to_int(int argc, char **argv, int *tab_a)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		tab_a[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
}

static void	reorganise_order_tab_a(int *tab_a, int size_a)
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
	convert_to_int(argc, argv, tab_a);
	replace_to_indice(tab_a, &size_a);
	is_in_lis(tab_a, &size_a, tab_b, &size_b);
}

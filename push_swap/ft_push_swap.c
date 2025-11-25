/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:56:14 by msuter            #+#    #+#             */
/*   Updated: 2025/11/25 12:49:30 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int verif_double(int *tab_a, int size_a)
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
				ft_printf("Error\n");
				return(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	valid_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
			{
				ft_printf("Error\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

static int	convert_to_int(int argc, char **argv, int *tab_a)
{
	int	i;
	int	j;
	int	error;
	long	verif;

	i = 1;
	j = 0;
	while (i < argc)
	{
		verif = ft_atol(argv[i]);
		if (min_max(verif) == 1)
		{
			ft_printf("Error\n");
			return (1);
		}
		else
			tab_a[j] = verif;
		i++;
		j++;
	}
	error = verif_double(tab_a, argc);
	if (error == 1)
		return (1);
	return (0);
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
	if(valid_number(argc, argv) == 1)
		return(free_all(tab_a, tab_b));
	if (convert_to_int(argc, argv, tab_a) == 1)
		return(free_all(tab_a, tab_b));
	replace_to_indice(tab_a, &size_a);
	is_in_lis(tab_a, &size_a, tab_b, &size_b);
	while (size_b != 0)
		who_push(tab_a, &size_a, tab_b, &size_b);
	reorganise_order_tab_a(tab_a, size_a);
	free(tab_a);
	free(tab_b);
	return (0);
}

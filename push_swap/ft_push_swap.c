/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:56:14 by msuter            #+#    #+#             */
/*   Updated: 2025/11/19 09:24:22 by msuter           ###   ########.fr       */
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

static void	nb_ra_or_rra(int *tab_a, int *size_a, int nb_rot)
{
	int	i;

	i = nb_rot;
	if (nb_rot > *size_a / 2)
	{
		while (i < *size_a)
		{
			rotate_reverse_a(tab_a, size_a);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			rotate_a(tab_a, size_a);
			i--;
		}
	}
}

static void	is_in_lis(int *tab_a, int *size_a, int *tab_b, int *size_b)
{
	int	*lis;
	int	size_lis;
	int	i;
	int	j;
	
	i = 0;
	size_lis = new_lis(*tab_a, size_a, *lis);
	while (i < tab_a)
	{
		j = 0;
		while(tab_a[i] == lis[j] && j < size_lis)
			j++;
		i++;
	}
	
}

int	main(int argc, char **argv)
{
	int	*tab_a;
	int	*tab_b;
	int	size_a;
	int	size_b;

	size_a = argc - 1;
	tab_a = malloc(sizeof(int) * size_a);
	convert_to_int(argc, argv, tab_a);
}

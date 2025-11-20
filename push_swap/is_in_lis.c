/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_lis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:03:14 by msuter            #+#    #+#             */
/*   Updated: 2025/11/20 10:04:23 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	find_index_not_in_lis(int *tab_a, int size_a, int *lis, int size_lis)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_a)
	{
		j = 0;
		while (j < size_lis && tab_a[i] != lis[j])
			j++;
		if (j == size_lis)
			return (i);
		i++;
	}
	return (-1);
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

void	is_in_lis(int *tab_a, int *size_a, int *tab_b, int *size_b)
{
	int	*lis;
	int	size_lis;
	int	to_push;
	int	idx;

	lis = NULL;
	size_lis = new_lis(tab_a, *size_a, &lis);
	if (!lis)
		return ;
	to_push = *size_a - size_lis;
	while (to_push > 0)
	{
		idx = find_index_not_in_lis(tab_a, *size_a, lis, size_lis);
		if (idx == -1)
			break ;
		nb_ra_or_rra(tab_a, size_a, idx);
		push_b(tab_a, size_a, tab_b, size_b);
		to_push--;
	}
	free(lis);
}
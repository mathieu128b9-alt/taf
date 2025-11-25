/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_min_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:06:58 by msuter            #+#    #+#             */
/*   Updated: 2025/11/25 13:02:10 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	cost_in_b(int index, int size_b)
{
	if (index > size_b / 2)
		return (size_b - index);
	return (index);
}

int	srch_min_in_a(int *tab_a, int size_a)
{
	int	index;
	int	i;

	i = 1;
	index = 0;
	while (i < size_a)
	{
		if (tab_a[i] < tab_a[index])
			index = i;
		i++;
	}
	return (index);
}

static int	cost_in_a(int *tab_a, int size_a, int value)
{
	int	target;

	target = find_target_index(tab_a, size_a, value);
	if (target > size_a / 2)
		return (size_a - target);
	return (target);
}

static int	which_rotate(int *nb_move, int size_b)
{
	int	i;
	int	min;

	i = 0;
	min = nb_move[0];
	while (i < size_b)
	{
		if (nb_move[i] < min)
			min = nb_move[i];
		i++;
	}
	return (min);
}

void	who_push(int *tab_a, int *size_a, int *tab_b, int *size_b)
{
	int	*nb_move;
	int	i;
	int	min;
	int	nb;

	i = 0;
	nb_move = malloc(sizeof(int) * (*size_b));
	if (!nb_move)
		return ;
	while (i < *size_b)
	{
		nb_move[i] = cost_in_a(tab_a, *size_a, tab_b[i])
			+ cost_in_b(i, *size_b);
		i++;
	}
	min = which_rotate(nb_move, *size_b);
	nb = 0;
	while (min != nb_move[nb])
		nb++;
	start_rot(tab_a, size_a, tab_b[nb]);
	start_rot_for_b(tab_b, size_b, nb);
	push_a(tab_a, size_a, tab_b, size_b);
	free(nb_move);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_min_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:06:58 by msuter            #+#    #+#             */
/*   Updated: 2025/11/23 20:50:11 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	direction(int i, int j, int size_a, int size_b)
{
	int	count;
	
	count = i;
	if (i > size_b / 2)
		count = size_b - i;
	if (j <= size_a / 2)
		count += j;
	else
		count += size_a - j;
	return (count);
}

static int	srch_min_in_a(int *tab_a, int size_a)
{
	int index;
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

static int	comp(int *tab_a, int *size_a, int *tab_b, int *size_b)
{
	static int	i;
	int	j;
	int	count;

	j = 0;
	if (i >= *size_b)
		i = 0;
	while (j + 1 < *size_a)
	{
		if (tab_b[i] > tab_a[j] && tab_b[i] < tab_a[j + 1])
			break;
		j++;
	}
	if (j == *size_a - 1)
		j = srch_min_in_a(tab_a, *size_a);
	count = direction(i, j, *size_a, *size_b);
	i++;
	
	return (count);
}

static int	which_rotate(int *nb_move, int *size_b)
{
	int	i;
	int	min;
	
	i = 0;
	min = nb_move[i];
	while (i < *size_b)
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
	int	na;
	int	min;
	int	nb;

	na = 0;
	nb = 0;
	nb_move = malloc(sizeof(int) * (*size_b));
	if (!nb_move)
		return ;
	while (na < *size_b)
	{
		nb_move[na] = comp(tab_a, size_a, tab_b, size_b);
		na++;
	}
	min = which_rotate(nb_move, *size_b);
	while (min != nb_move[nb])
		nb++;
	na = min - nb;
	nb_rot_in_a(tab_a, *size_a, na);
}
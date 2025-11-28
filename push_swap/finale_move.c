/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finale_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:19:37 by msuter            #+#    #+#             */
/*   Updated: 2025/11/28 09:27:01 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	find_target_index(int *tab_a, int size_a, int value)
{
	int	i;
	int	best_index;

	best_index = -1;
	i = 0;
	while (i < size_a)
	{
		if (tab_a[i] < value)
		{
			if (best_index == -1 || tab_a[i] > tab_a[best_index])
				best_index = i;
		}
		i++;
	}
	if (best_index == -1)
		best_index = srch_max_in_a(tab_a, size_a);
	best_index++;
	if (best_index >= size_a)
		best_index = 0;
	return (best_index);
}

int	srch_max_in_a(int *tab_a, int size_a)
{
	int	i;
	int	index;

	index = 0;
	i = 1;
	while (i < size_a)
	{
		if (tab_a[i] > tab_a[index])
			index = i;
		i++;
	}
	return (index);
}

void	start_rot(int *tab, int *size, int value)
{
	int	target;
	int	tmp;

	target = find_target_index(tab, *size, value);
	if (target > *size / 2)
	{
		tmp = *size - target;
		while (tmp-- > 0)
			rotate_reverse_a(tab, size);
	}
	else
	{
		tmp = target;
		while (tmp-- > 0)
			rotate_a(tab, size);
	}
}

void	start_rot_for_b(int *tab_b, int *size_b, int index)
{
	int	tmp;

	if (*size_b < 2)
		return ;
	if (index > *size_b / 2)
	{
		tmp = *size_b - index;
		while (tmp-- > 0)
			reverse_rotate_b(tab_b, size_b);
	}
	else
	{
		tmp = index;
		while (tmp-- > 0)
			rotate_b(tab_b, size_b);
	}
}

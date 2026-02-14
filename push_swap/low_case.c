/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:25:28 by msuter            #+#    #+#             */
/*   Updated: 2026/02/14 15:47:09 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	sort_two(int *tab_a, int *size_a)
{
	if (tab_a[0] > tab_a[1])
		swap_a(tab_a, size_a);
}

static void	sort_three(int *tab_a, int *size_a)
{
	sort_two(tab_a, size_a);
	if (tab_a[2] > tab_a[0] && tab_a[2] < tab_a[1])
	{
		rotate_reverse_a(tab_a, size_a);
		swap_a(tab_a, size_a);
	}
	else if (tab_a[2] < tab_a[0])
		rotate_reverse_a(tab_a, size_a);
}

static void	sort_four(int *tab_a, int *tab_b, int *size_a, int *size_b)
{
	int	index;

	index = srch_min_in_a(tab_a, *size_a);
	if (index > *size_a / 2)
	{
		while (index != 0)
		{
			rotate_reverse_a(tab_a, size_a);
			index--;
		}
	}
	else
	{
		while (index != 0)
		{
			rotate_a(tab_a, size_a);
			index--;
		}
	}
	push_b(tab_a, size_a, tab_b, size_b);
	sort_three(tab_a, size_a);
	push_a(tab_a, size_a, tab_b, size_b);
}

static void	sort_five(int *tab_a, int *tab_b, int *size_a, int *size_b)
{
	int	index;

	index = srch_min_in_a(tab_a, *size_a);
	if (index > *size_a / 2)
	{
		while (index != 0)
		{
			rotate_reverse_a(tab_a, size_a);
			index--;
		}
	}
	else
	{
		while (index != 0)
		{
			rotate_a(tab_a, size_a);
			index--;
		}
	}
	push_b(tab_a, size_a, tab_b, size_b);
	sort_four(tab_a, tab_b, size_a, size_b);
	push_a(tab_a, size_a, tab_b, size_b);
}

void	sort_stack(int *tab_a, int *tab_b, int *size_a, int *size_b)
{
	*size_b = 0;
	replace_to_indice(tab_a, size_a);
	if (*size_a == 2)
		sort_two(tab_a, size_a);
	else if (*size_a == 3)
		sort_three(tab_a, size_a);
	else if (*size_a == 4)
		sort_four(tab_a, tab_b, size_a, size_b);
	else if (*size_a == 5)
		sort_five(tab_a, tab_b, size_a, size_b);
	else
	{
		is_in_lis(tab_a, size_a, tab_b, size_b);
		while (*size_b != 0)
			who_push(tab_a, size_a, tab_b, size_b);
		reorganise_order_tab_a(tab_a, *size_a);
	}
}

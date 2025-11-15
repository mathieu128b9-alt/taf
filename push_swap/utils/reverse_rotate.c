/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:05:37 by msuter            #+#    #+#             */
/*   Updated: 2025/11/15 16:31:20 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rotate_reverse_a(int *tab_a, int *size_a)
{
	int	temp;
	int	i;

	if (*size_a < 2)
		return ;
	i = *size_a - 1;
	temp = tab_a[*size_a - 1];
	while (i > 0)
	{
		tab_a[i] = tab_a[i - 1];
		i--;
	}
	tab_a[0] = temp;
	ft_printf("rra\n");
}

void	reverse_rotate_b(int *tab_b, int *size_b)
{
	int	temp;
	int	i;

	if (*size_b < 2)
		return ;
	i = *size_b - 1;
	temp = tab_b[*size_b - 1];
	while (i > 0)
	{
		tab_b[i] = tab_b[i - 1];
		i--;
	}
	tab_b[0] = temp;
	ft_printf("rrb\n");
}

static void	silent_rotate_reverse_a(int *tab_a, int *size_a)
{
	int	temp;
	int	i;

	if (*size_a < 2)
		return ;
	i = *size_a - 1;
	temp = tab_a[*size_a - 1];
	while (i > 0)
	{
		tab_a[i] = tab_a[i - 1];
		i--;
	}
	tab_a[0] = temp;
}

static void	silent_reverse_rotate_b(int *tab_b, int *size_b)
{
	int	temp;
	int	i;

	if (*size_b < 2)
		return ;
	i = *size_b - 1;
	temp = tab_b[*size_b - 1];
	while (i > 0)
	{
		tab_b[i] = tab_b[i - 1];
		i--;
	}
	tab_b[0] = temp;
}

void	rev_rot_both(int *tab_a, int *tab_b, int *size_a, int *size_b)
{
	if (*size_a < 2 || *size_b < 2)
		return ;
	silent_rotate_reverse_a(tab_a, size_a);
	silent_reverse_rotate_b(tab_b, size_b);
	ft_printf("rrr\n");
}
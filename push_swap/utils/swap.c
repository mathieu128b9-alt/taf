/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:23:39 by msuter            #+#    #+#             */
/*   Updated: 2025/11/10 20:03:40 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap_a(int *tab_a, int *size_a)
{
	int	temp;

	if (*size_a < 1)
		return ;
	temp = tab_a[0];
	tab_a[0] = tab_a[1];
	tab_a[1] = temp;
	ft_printf("sa\n");
}

void	swap_b(int *tab_b, int *size_b)
{
	int	temp;

	if (*size_b < 1)
		return ;
	temp = tab_b[0];
	tab_b[0] = tab_b[1];
	tab_b[1] = temp;
	ft_printf("sb\n");
}

static void	silent_swap_a(int *tab_a, int *size_a)
{
	int	temp;

	if (*size_a < 1)
		return ;
	temp = tab_a[0];
	tab_a[0] = tab_a[1];
	tab_a[1] = temp;
}

static void	silent_swap_b(int *tab_b, int *size_b)
{
	int	temp;

	if (*size_b < 1)
		return ;
	temp = tab_b[0];
	tab_b[0] = tab_b[1];
	tab_b[1] = temp;
}

void	swap_both(int *tab_a, int *tab_b, int *size_a, int *size_b)
{
	int	temp;

	if (size_a >= 1)
	{
		temp = tab_a[0];
		tab_a[0] = tab_a[1];
		tab_a[1] = temp;
	}
	if (size_b >= 1)
	{
		temp = tab_b[0];
		tab_b[0] = tab_b[1];
		tab_b[1] = temp;
	}
	ft_printf("ss\n");
}
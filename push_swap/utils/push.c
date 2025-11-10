/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:18:51 by msuter            #+#    #+#             */
/*   Updated: 2025/11/08 20:55:47 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push_a(int *tab_a, int *tab_b, int *size_a, int *size_b)
{
	int	i;

	if (*size_b < 1)
		return ;
	i = *size_a;
	while (i > 0)
	{
		tab_a[i] = tab_a[i - 1];
		i--;
	}
	tab_a[0] = tab_b[0];
	(*size_a)++;
	i = 0;
	while (i < *size_b - 1)
	{
		tab_b[i] = tab_b[i + 1];
		i++;
	}
	(*size_b)--;
	ft_printf("pa\n");
}

void	push_b(int *tab_a, int *tab_b, int *size_a, int *size_b)
{
	int	i;

	if (*size_a < 1)
		return ;
	i = *size_b;
	while (i > 0)
	{
		tab_b[i] = tab_b[i - 1];
		i--;
	}
	tab_b[0] = tab_a[0];
	(*size_b)++;
	i = 0;
	while (i < *size_a - 1)
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}
	(*size_a)--;
	ft_printf("pb\n");
}

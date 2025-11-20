/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:55:56 by msuter            #+#    #+#             */
/*   Updated: 2025/11/20 16:05:53 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rotate_a(int *tab_a, int *size_a)
{
	int	temp;
	int	i;

	i = 0;
	if (*size_a < 2)
		return ;
	temp = tab_a[0];
	while (i < *size_a - 1)
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}
	tab_a[*size_a - 1] = temp;
	ft_printf("ra\n");
}

void	rotate_b(int *tab_b, int *size_b)
{
	int	temp;
	int	i;

	i = 0;
	if (*size_b < 2)
		return ;
	temp = tab_b[0];
	while (i < *size_b - 1)
	{
		tab_b[i] = tab_b[i + 1];
		i++;
	}
	tab_b[*size_b - 1] = temp;
	ft_printf("rb\n");
}

static void	silent_rotate_a(int *tab_a, int *size_a)
{
	int	temp;
	int	i;

	i = 0;
	if (*size_a < 2)
		return ;
	temp = tab_a[0];
	while (i < *size_a - 1)
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}
	tab_a[*size_a - 1] = temp;
}

static void	silent_rotate_b(int *tab_b, int *size_b)
{
	int	temp;
	int	i;

	i = 0;
	if (*size_b < 2)
		return ;
	temp = tab_b[0];
	while (i < *size_b - 1)
	{
		tab_b[i] = tab_b[i + 1];
		i++;
	}
	tab_b[*size_b - 1] = temp;
}
void	rotate_both(int *tab_a, int *tab_b, int size_a, int size_b)
{
	if (size_a >= 2)
		silent_rotate_a(tab_a, &size_a);
	if (size_b >= 2)
		silent_rotate_b(tab_b, &size_b);
	ft_printf("rr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_min_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:06:58 by msuter            #+#    #+#             */
/*   Updated: 2025/11/23 15:20:05 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
	count = i;
	if (i > *size_b / 2)
		count = *size_b - i;
	if (j <= *size_a / 2)
		count += j;
	else
		count += *size_a - j;
	i++;
	return (count);
}

void	who_push(int *tab_a, int *size_a, int *tab_b, int *size_b)
{
	int	*nb_move;
	int	i;

	i = 0;
	nb_move = malloc(sizeof(int) * (*size_b));
	while (i < size_b)
}
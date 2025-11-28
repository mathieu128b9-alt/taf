/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_lis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:03:14 by msuter            #+#    #+#             */
/*   Updated: 2025/11/28 09:33:49 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	is_in_lis(int *tab_a, int *size_a, int *tab_b, int *size_b)
{
	int	*lis;
	int	size_lis;
	int	count;
	int	j;

	lis = NULL;
	size_lis = new_lis(tab_a, *size_a, &lis);
	if (!lis)
		return ;
	count = *size_a;
	while (count--)
	{
		j = 0;
		while (j < size_lis && tab_a[0] != lis[j])
			j++;
		if (j < size_lis)
			rotate_a(tab_a, size_a);
		else
			push_b(tab_a, size_a, tab_b, size_b);
	}
	free(lis);
}

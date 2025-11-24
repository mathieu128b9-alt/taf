/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_lis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:03:14 by msuter            #+#    #+#             */
/*   Updated: 2025/11/24 16:57:35 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	is_in_lis(int *tab_a, int *size_a, int *tab_b, int *size_b)
{
	int	*lis;
	int	size_lis;
	int	orig_size;
	int	i;
	int	j;
	int	in_lis;

	lis = NULL;
	size_lis = new_lis(tab_a, *size_a, &lis);
	if (!lis)
		return ;
	orig_size = *size_a;
	i = 0;
	while (i < orig_size)
	{
		in_lis = 0;
		j = 0;
		while (j < size_lis)
		{
			if (tab_a[0] == lis[j])
				in_lis = 1;
			j++;
		}
		if (in_lis)
			rotate_a(tab_a, size_a);
		else
			push_b(tab_a, size_a, tab_b, size_b);
		i++;
	}
	free(lis);
}
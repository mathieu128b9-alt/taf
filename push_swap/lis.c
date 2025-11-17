/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:41:37 by msuter            #+#    #+#             */
/*   Updated: 2025/11/17 19:58:05 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void mall_and_allocate(int **len, int **prev, int size)
{
	int i;

	i = 0;
	*len = malloc(sizeof(int) * size);
	if (!*len)
		return ;
	*prev = malloc(sizeof(int) * size);
	if (!*prev)
	{
		free (*len);
		return ;
	}
		while (i < size)
	{
		(*len)[i] = 1;
		(*prev)[i] = -1;
		i++;
	}
}

static void	find_lis(int *tab_a, int *size_a, int *len, int *prev)
{
	int	i;
	int	j;

	i = 0;
	mall_and_allocate(&len, &prev, *size_a);
	while (i < *size_a)
	{
		j = 0;
		while (j < i)
		{
			if (tab_a[j] < tab_a[i] && len[j] + 1 > len[i])
			{
				len[i] = len[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

void	search_max_lis(int *tab_a, int *size_a, int *len, int *prev, int **lis)
{
	int	i;
	int	max_in_len;
	int	index_pos;
	
	i = 0;
	max_in_len = 0;
	while (i < *size_a)
	{
		if (max_in_len < len[i])
			max_in_len = len[i];
		i++;
	}
	*lis = malloc(sizeof(int) * max_in_len);
	i = 0;
	index_pos = max_in_len;
	while (len[i] != max_in_len)
		i++;
	while (i != -1)
	{
		lis[] = tab_a[i];
		i = prev[i];
		index_pos--;
	}
}

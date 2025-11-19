/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:41:37 by msuter            #+#    #+#             */
/*   Updated: 2025/11/19 08:07:54 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	verif_mall(int **tab, int size)
{
	*tab = malloc(sizeof(int) * size);
	if (!*tab)
		return ;
}

static void	mall_and_allocate(int **len, int **prev, int size)
{
	int	i;

	*len = malloc(sizeof(int) * size);
	if (!*len)
		return ;
	*prev = malloc(sizeof(int) * size);
	if (!*prev)
	{
		free(*len);
		return ;
	}
	i = 0;
	while (i < size)
	{
		(*len)[i] = 1;
		(*prev)[i] = -1;
		i++;
	}
}

static void	find_lis(int *tab_a, int size_a, int *len, int *prev)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_a)
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

static int	*search_lis(int *tab_a, int size_a, int *len, int *prev)
{
	int	*lis;
	int	i;
	int	max_len;
	int	pos;

	max_len = 0;
	i = -1;
	while (++i < size_a)
		if (len[i] > max_len)
			max_len = len[i];
	verif_mall(&lis, max_len);
	if (!lis)
		return (NULL);
	pos = max_len - 1;
	i = size_a - 1;
	while (i >= 0 && len[i] != max_len)
		i--;
	while (i != -1)
	{
		lis[pos--] = tab_a[i];
		i = prev[i];
	}
	return (lis);
}

int	new_lis(int *tab_a, int size_a, int **lis)
{
	int	*len;
	int	*prev;
	int	lis_size;
	int	i;

	len = NULL;
	prev = NULL;
	mall_and_allocate(&len, &prev, size_a);
	if (!len || !prev)
		return (0);
	find_lis(tab_a, size_a, len, prev);
	lis_size = 0;
	i = 0;
	while (i < size_a)
	{
		if (len[i] > lis_size)
			lis_size = len[i];
		i++;
	}
	*lis = search_lis(tab_a, size_a, len, prev);
	free(len);
	free(prev);
	if (!*lis)
		return (0);
	return (lis_size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:41:37 by msuter            #+#    #+#             */
/*   Updated: 2025/11/24 16:27:48 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
		*len = NULL;
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
	int	max_len;
	int	last;
	int	i;

	max_len = 0;
	last = 0;
	i = 0;
	while (i < size_a)
	{
		if (len[i] > max_len)
		{
			max_len = len[i];
			last = i;
		}
		i++;
	}
	verif_mall(&lis, max_len);
	if (!lis)
		return (NULL);
	i = max_len - 1;
	while (i >= 0)
	{
		lis[i] = tab_a[last];
		last = prev[last];
		i--;
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
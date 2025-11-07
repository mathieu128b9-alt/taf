/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_reatribute.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:00:06 by msuter            #+#    #+#             */
/*   Updated: 2025/11/07 22:23:38 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


int	count_tab(int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i + 1);
}

void	reatribute(int *tab, int *tab_temp, int *size, int start)
{
	int	i;

	i = 0;
	while (start < *size)
	{
		tab_temp[start] = tab[i];
		start++;
		i++;
	}
}

void	malloc_and_verif(int *tab, int size)
{
	tab = malloc(sizeof(int) * size);
	if(!tab)
		return (NULL);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:05:25 by msuter            #+#    #+#             */
/*   Updated: 2025/11/15 16:43:42 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
//#include "stdlib.h"
static void	assign_tab(int *tab_a, int *index, int *size_a)
{
	int	i;

	i = 0;
	while (i < *size_a)
	{
		tab_a[i] = index[i];
		i++;
	}
}

void	replace_to_indice(int *tab_a, int *size_a)
{
	int	*index;
	int	i;
	int	count;
	int	j;

	index = malloc(sizeof(int) * (*size_a));
	j = 0;
	while (j < *size_a)
	{
		i = 0;
		count = 0;
		while (i < *size_a)
		{
			if (tab_a[i] < tab_a[j])
				count++;
			i++;
		}
		index[j] = count;
		j++;
	}
	assign_tab(tab_a, index, size_a);
	free(index);
}

//#include "stdio.h"
//int main(void)
//{
//	int i;
//	int size = 6;
//	i = 0;
//	int tab[] = {10, 17, 2, 45, 5, 9};
//	replace_to_indice(tab, &size);
//	while (i < 6)
//	{
//		printf("%d", tab[i]);
//		i++;
//	}
//}
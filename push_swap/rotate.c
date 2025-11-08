/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:55:56 by msuter            #+#    #+#             */
/*   Updated: 2025/11/08 21:31:35 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rotate_a(int *tab_a, int *size_a)
{
	int	temp;
	int	i;

	i = 0;
	temp = tab_a[*size_a - 1];
	while (i < *size_a - 1)				// FAUXXXXXXXXXXXXXXXXXXX recommencer
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}
	tab_a[0] = temp;
}
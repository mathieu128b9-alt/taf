/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finale_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:19:37 by msuter            #+#    #+#             */
/*   Updated: 2025/11/23 20:51:20 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"



void	nb_rot_in_a(int *tab_a, int *size_a, int na)
{
	int	i;

	i = 0;
	if (na > *size_a / 2)
	{
		while (i++ < na)
		{
			rotate_reverse_a(tab_a, size_a);
		}
	}
	else
	{
		while (i++ < na)
			rotate_a(tab_a, size_a);
	}
}

void	nb_rot_in_b(int *tab_b, int *size_b, int nb)
{
	int	i;

	i = 0;
	while (i++ < nb)
		rotate_a(tab_b, *size_b);
}


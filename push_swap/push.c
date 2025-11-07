/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:18:51 by msuter            #+#    #+#             */
/*   Updated: 2025/11/07 22:36:15 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push_a(int *tab_a, int *tab_b, int *size_a, int *size_b)
{
	int	*tab_temp;
	if (*size_b < 1)
		return ;
		*size_a++;
		malloc_and_verif(tab_temp, size_a);
		tab_temp[0] = tab_b[0];
		reatribute(tab_a, tab_temp, size_a, 1);
		free(tab_a);
		malloc_and_verif(tab_a, size_a);
		reatribute(tab_temp, tab_a, size_a, 0);
		free(tab_temp);
		*size_b--;
		malloc_and_verif(tab_temp, size_b);
		reatribute(tab_b, tab_temp, size_b, 1);
		free(tab_b);
		malloc_and_verif(tab_b, size_b);
		reatribute(tab_temp, tab_b, size_b, 0);
		free(tab_temp);
}
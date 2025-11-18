/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:56:14 by msuter            #+#    #+#             */
/*   Updated: 2025/11/18 20:29:55 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	convert_to_int(int argc, char **argv, int *tab_a)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		tab_a[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
}

int	main(int argc, char **argv)
{
	int	*tab_a;
	int	*tab_b;
	int	size_a;
	int	size_b;

	size_a = argc - 1;
	tab_a = malloc(sizeof(int) * size_a);
	convert_to_int(argc, argv, tab_a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:56:14 by msuter            #+#    #+#             */
/*   Updated: 2025/11/20 10:29:22 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	convert_to_int(int argc, char **argv, int *tab_a)
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
	int	size_b;
	int	size_a;

	size_a = argc - 1;
	tab_a = malloc(sizeof(int) * size_a);
	size_b = argc - 1;
	tab_b = malloc(sizeof(int) * size_b);
	convert_to_int(argc, argv, tab_a);
	replace_to_indice(tab_a, &size_a);
	is_in_lis(tab_a, &size_a, tab_b, &size_b);

	//int i = 0;
	//int j = 0;
	//ft_printf("je print moon taba, \n");
	//while (i < size_a)
	//{
	//	ft_printf("%d\n", tab_a[i]);
	//	i++;
	//}
	//ft_printf("je print moon tabb, \n");
	//while (j < size_b)
	//{
	//	ft_printf("%d\n", tab_b[j]);
	//	j++;
	//}
}

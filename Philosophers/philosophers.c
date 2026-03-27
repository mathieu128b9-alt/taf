/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:50:29 by msuter            #+#    #+#             */
/*   Updated: 2026/03/27 23:34:53 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	verif_and_attrib_gen(int	argc, char **argv, t_gen *gen)
{
	if (!(argc >= 5 && argc <= 6))
	{
		printf("les arguments requis sont:\n nb_philo\n\
			temp_avant_mort\n temps_avant_manger\n\
			temps_avant_dormir\n nb_de_fois_a_manger\n");
		exit(1);
	}
	gen->nb_philo = ft_atoi_c(argv[1]);
	gen->ti_to_die = ft_atoi_c(argv[2]);
	gen->ti_to_eat = ft_atoi_c(argv[3]);
	gen->ti_to_sleep = ft_atoi_c(argv[4]);
	if (argv[5] == NULL)
		gen->must_eat = -1;
	else
		gen->must_eat = ft_atoi_c(argv[5]);
	
}

int main (int argc, char **argv)
{
	t_gen	*gen;
	t_philo	*philo;
	verif_and_attrib(argc, argv, gen);
}
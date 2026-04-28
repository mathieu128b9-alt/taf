/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:50:29 by msuter            #+#    #+#             */
/*   Updated: 2026/04/29 00:54:59 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main (int argc, char **argv)
{
	t_gen	gen;
	int		i;

	i = 0;
	verif_and_attrib_gen(argc, argv, &gen);
	while (i < gen.nb_philo)
	{
		if (pthread_create(&gen.philo[i].thread, NULL, philo_routine, &gen.philo[i]) != 0)
		{
			stop_simu(&gen);
			cleanup(&gen, i);
			exit (1);
		}
		i++;
	}
	pthread_create(&gen.state, NULL, verif_philo, &gen);
	while (i >= 0)
	{
		i--;
		pthread_join(gen.philo[i].thread, NULL);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:50:29 by msuter            #+#    #+#             */
/*   Updated: 2026/03/27 19:12:18 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	verif(int	argc, char **argv)
{
	if (argc != 6)
	{
		printf("les arguments requis sont:\n nb_philo\n\
			temp_avant_mort\n temps_avant_manger\n\
			temps_avant_dormir\n nb_de_fois_a_manger\n");
		exit(1);
	}
	
}

int main (int argc, char **argv)
{
	t_gen	*gen;
	t_philo	*philo;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:50:34 by msuter            #+#    #+#             */
/*   Updated: 2026/03/27 19:12:16 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_gen t_gen;
typedef struct s_philo
{
	int				num;
	long			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	t_gen			*gen;

}	t_philo;

typedef struct s_gen
{
	long			ti_to_die;
	long			ti_to_sleep;
	long			ti_to_eat;
	int				nb_philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	logs;
	int				p_running;
	t_philo			*philo;
	pthread_t		state;
	pthread_mutex_t	protect_p;
	int				must_eat;

}	t_gen;


#endif
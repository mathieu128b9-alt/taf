/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_segment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:37:05 by msuter            #+#    #+#             */
/*   Updated: 2025/12/04 17:53:23 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	*thread(void *arg)
{
	t_thread	*thread;
	t_all		*all;
	int			y;
	int			y_end;
	int			x;

	thread = (t_thread *)arg;
	all = thread->all;
	y = thread->thrd_y_srt;
	y_end = thread->thrd_y_end;
	while (y < y_end)
	{
		x = 0;
		while (x < all->g.width)
		{
			put_pixel(all, x, y);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	creation_thread(pthread_t *thread_id, t_thread *thread_stk)
{
	int	i;

	i = 0;
	while (i < N_THREAD)
	{
		pthread_create(&thread_id[i], NULL, thread, &thread_stk[i]);
		i++;
	}
	i = 0;
	while (i < N_THREAD)
	{
		pthread_join(thread_id[i], NULL);
		i++;
	}
}
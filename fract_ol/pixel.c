/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:02:37 by msuter            #+#    #+#             */
/*   Updated: 2025/12/06 00:17:32 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double mandelbroot(t_all *all, double i, double mandel_c_re, double mandel_c_im)
{
	double	temp;
	double	z_re;
	double	z_im;
	double	verif_max_nb;
	
	i = 0;
	z_re = 0;
	z_im = 0;
	verif_max_nb = 0;
	while (i < all->f.max_iter)
	{
		temp = z_re;
		z_re = ((z_re * z_re) - (z_im * z_im)) + mandel_c_re;
		z_im = ((2 * temp) * z_im) + mandel_c_im;
		verif_max_nb = z_re * z_re + z_im *z_im;
		if (verif_max_nb > 4)
			return (i + 1 - log(log(sqrt(z_re * z_re + z_im * z_im))) / log(2));
		i++;
	}
	return (i);
}

static int	is_in_window(t_all *all, int x, int y)
{
	if (x >= 0 && x < all->g.width)
		if (y >= 0 && y < all->g.height)
			return (0);
	return (1);
}

void	color_pixel(t_all *all, int offset_total, double i)
{
	double	t;

	t = i / all->f.max_iter;
	if (i == all->f.max_iter)
	{
		all->g.addr[offset_total] = 0;
		all->g.addr[offset_total + 1] = 0;
		all->g.addr[offset_total + 2] = 0;
	}
	else
	{
		all->g.addr[offset_total] = all->f.color_r + 127 * cos(2 * N_PI * t);
		all->g.addr[offset_total + 1] = all->f.color_g + 127 * cos(2 * N_PI * t + 2);
		all->g.addr[offset_total + 2] = all->f.color_b + 127 * cos(2 * N_PI * t + 4);
	}
}

int	put_pixel(t_all *all, int x, int y)
{
	double	c_im;
	double	c_re;
	int	offset_y;
	int	offset_x;
	double	i;

	c_im = all->f.max_im + y * all->z.scale_im;
	c_re = all->f.min_re + x * all->z.scale_re;
	if (is_in_window(all, x, y) == 1)
		return (1);
	offset_y = y * all->g.len_line;
	offset_x = x * all->g.bytes_per_pixel;
	i = mandelbroot(all, 0, c_re, c_im);
	color_pixel(all, (offset_x + offset_y), i);
	return (0);
}

int	display(t_all *all)
{
	pthread_t	thread_id[N_THREAD];
	t_thread	thread_stk[N_THREAD];
	int			slice;
	int			i;

	i = 0;
	slice = all->g.height / N_THREAD;
	all->z.scale_re = (all->f.max_re - all->f.min_re)/all->g.width;
	all->z.scale_im = (all->f.min_im - all->f.max_im)/ all->g.height;
	while (i < N_THREAD)
	{
		thread_stk[i].all = all;
		thread_stk[i].thrd_y_srt = i * slice;
		if (i == N_THREAD - 1)
			thread_stk[i].thrd_y_end = all->g.height;
		else
			thread_stk[i].thrd_y_end = (i + 1) * slice;

		i++;
	}
	creation_thread(thread_id, thread_stk);

	return (0);
}

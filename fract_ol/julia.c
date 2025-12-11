/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:44:06 by msuter            #+#    #+#             */
/*   Updated: 2025/12/11 08:19:48 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_motion(int x, int y, void *param)
{
	t_all *all;

	all = param;
	if ((all->f.mode == 2 || all->f.mode == 3) && all->f.julia_fix % 2 == 0)
	{
		all->z.mouse_re = (((all->f.max_re - all->f.min_re)
				/ all->g.width) * x) + all->f.min_re;
		all->z.mouse_im = all->f.max_im
			-(((all->f.max_im - all->f.min_im) / all->g.height) * y);
		all->f.julia_c_re = all->z.mouse_re;
		all->f.julia_c_im = all->z.mouse_im;
		display(all);
		mlx_put_image_to_window(all->g.mlx_ptr, all->g.win_ptr, all->g.img_ptr, 0, 0);
		return (1);
	}
	else
		return (0);
}

double	julia(t_all *all, double i, double mandel_c_re, double mandel_c_im)
{
	double	temp;
	double	z_re;
	double	z_im;
	double	verif_max_nb;
	
	i = 0;
	z_re = mandel_c_re;
	z_im = mandel_c_im;
	verif_max_nb = 0;
	while (i < all->f.max_iter)
	{
		temp = z_re;
		z_re = ((z_re * z_re) - (z_im * z_im)) + all->f.julia_c_re;
		z_im = ((2 * temp) * z_im) + all->f.julia_c_im;
		verif_max_nb = z_re * z_re + z_im *z_im;
		if (verif_max_nb > 4)
			return (i + 1 - log(log(sqrt(z_re * z_re + z_im * z_im))) / log(2));
		i++;
	}
	return (i);
}

double	phoenix_julia(t_all *all, double iter, double z_re, double z_im)
{
	double	temp_re;
	double	z_prev_re;
	double	z_prev_im;

	iter = 0;
	z_prev_re = 0.0;
	z_prev_im = 0.0;
	while (iter < all->f.max_iter)
	{
		temp_re = z_re;
		z_prev_re = z_re;
		z_prev_im = z_im;
		z_re = temp_re * temp_re - z_im * z_im
			+ all->f.julia_c_re + all->f.phoenix_p_re * z_prev_re
			- all->f.phoenix_p_im * z_prev_im;
		z_im = 2 * temp_re * z_im
			+ all->f.julia_c_im + all->f.phoenix_p_re * z_prev_im
			+ all->f.phoenix_p_im * z_prev_re;
		if (z_re * z_re + z_im * z_im > 4.0)
			return (iter);
		iter++;
	}
	return (iter);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:56:25 by msuter            #+#    #+#             */
/*   Updated: 2025/12/01 19:15:02 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	mouse_point(t_all *all)
{
	mlx_mouse_get_pos(all->g.mlx_ptr, all->g.win_ptr,
		&all->z.mouse_x, &all->z.mouse_y);
	all->z.mouse_re = (((all->f.max_re - all->f.min_re)
				/ all->g.width) * all->z.mouse_x) + all->f.min_re;
	all->z.mouse_im = all->f.max_im
		-(((all->f.max_im - all->f.min_im) / all->g.height) * all->z.mouse_y);
}

void	zoom_in_screen(t_all *all)
{
	double	old_min_re;
	double	old_max_re;
	double	old_min_im;
	double	old_max_im;

	mouse_point(all);
	old_min_re = all->f.min_re;
	old_max_re = all->f.max_re;
	old_min_im = all->f.min_im;
	old_max_im = all->f.max_im;
	all->f.min_re = all->z.mouse_re + (old_min_re - all->z.mouse_re) * all->z.ratio_zoom;
	all->f.max_re = all->z.mouse_re + (old_max_re - all->z.mouse_re) * all->z.ratio_zoom;
	all->f.min_im = all->z.mouse_im + (old_min_im - all->z.mouse_im) * all->z.ratio_zoom;
	all->f.max_im = all->z.mouse_im + (old_max_im - all->z.mouse_im) * all->z.ratio_zoom;
	display(all);
	mlx_put_image_to_window(all->g.mlx_ptr, all->g.win_ptr, all->g.img_ptr, 0, 0);
}

int	which_button(int keycode, void *param)
{
	t_all *all;
	all = param;
	if (keycode == KEY_PLUS)
		zoom_in_screen(all);
	return (0);
}

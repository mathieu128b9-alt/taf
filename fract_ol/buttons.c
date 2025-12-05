/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:56:25 by msuter            #+#    #+#             */
/*   Updated: 2025/12/05 17:36:15 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

#include "stdio.h"

void	mouse_point(t_all *all)
{
	mlx_mouse_get_pos(all->g.mlx_ptr, all->g.win_ptr,
		&all->z.mouse_x, &all->z.mouse_y);
	all->z.mouse_re = (((all->f.max_re - all->f.min_re)
				/ all->g.width) * all->z.mouse_x) + all->f.min_re;
	all->z.mouse_im = all->f.max_im
		-(((all->f.max_im - all->f.min_im) / all->g.height) * all->z.mouse_y);
}

void	zoom_in(t_all *all)
{
	double	old_min_re;
	double	old_max_re;
	double	old_min_im;
	double	old_max_im;
	double	zoom_level;

	mouse_point(all);
	old_min_re = all->f.min_re;
	old_max_re = all->f.max_re;
	old_min_im = all->f.min_im;
	old_max_im = all->f.max_im;
	all->f.min_re = all->z.mouse_re + (old_min_re - all->z.mouse_re) * all->z.ratio_zoom_in;
	all->f.max_re = all->z.mouse_re + (old_max_re - all->z.mouse_re) * all->z.ratio_zoom_in;
	all->f.min_im = all->z.mouse_im + (old_min_im - all->z.mouse_im) * all->z.ratio_zoom_in;
	all->f.max_im = all->z.mouse_im + (old_max_im - all->z.mouse_im) * all->z.ratio_zoom_in;
	all->z.current_range_re = all->f.max_re - all->f.min_re;
	zoom_level = all->z.initial_range_re / all->z.current_range_re;
	if (all->f.max_iter < 2000)
		all->f.max_iter = 200 + (10 * log(zoom_level));
	display(all);
	mlx_put_image_to_window(all->g.mlx_ptr, all->g.win_ptr, all->g.img_ptr, 0, 0);
}

void	zoom_out(t_all *all)
{
	double	old_min_re;
	double	old_max_re;
	double	old_min_im;
	double	old_max_im;
	double	zoom_level;

	mouse_point(all);
	old_min_re = all->f.min_re;
	old_max_re = all->f.max_re;
	old_min_im = all->f.min_im;
	old_max_im = all->f.max_im;
	all->f.min_re = all->z.mouse_re + (old_min_re - all->z.mouse_re) * all->z.ratio_zoom_out;
	all->f.max_re = all->z.mouse_re + (old_max_re - all->z.mouse_re) * all->z.ratio_zoom_out;
	all->f.min_im = all->z.mouse_im + (old_min_im - all->z.mouse_im) * all->z.ratio_zoom_out;
	all->f.max_im = all->z.mouse_im + (old_max_im - all->z.mouse_im) * all->z.ratio_zoom_out;
	all->z.current_range_re = all->f.max_re - all->f.min_re;
	zoom_level = all->z.initial_range_re / all->z.current_range_re;
	if (all->f.max_iter < 2000)
		all->f.max_iter = 200 + (10 * log(zoom_level));
	display(all);
	mlx_put_image_to_window(all->g.mlx_ptr, all->g.win_ptr, all->g.img_ptr, 0, 0);
}

int	which_button(int keycode, void *param)
{
	t_all *all;
	all = param;
	
	if (keycode == KEY_LEFT)
		move_left(all);
	else if (keycode == KEY_RIGHT)
		move_right(all);
	else if (keycode == KEY_TOP)
		move_top(all);
	else if (keycode == KEY_BOT)
		move_bot(all);
	else if (keycode == KEY_ESC)
		finish_prog(all);
	return (0);
}

int which_mouse_button(int keycode, int x, int y, void *param)
{
	t_all *all;

	(void)x;
	(void)y;
	all = param;
	if (keycode == KEY_ZOOM)
		zoom_in(all);
	else if (keycode == KEY_UNZOOM)
		zoom_out(all);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:07:36 by msuter            #+#    #+#             */
/*   Updated: 2025/12/11 08:41:51 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	move_right(t_all *all)
{
	double	range_re;
	double	step_re;

	range_re = all->f.max_re - all->f.min_re;
	step_re = range_re * 0.05;
	all->f.max_re += step_re;
	all->f.min_re += step_re;
	display(all);
	mlx_put_image_to_window(all->g.mlx_ptr,
		all->g.win_ptr, all->g.img_ptr, 0, 0);
}

void	move_left(t_all *all)
{
	double	range_re;
	double	step_re;

	range_re = all->f.max_re - all->f.min_re;
	step_re = range_re * 0.05;
	all->f.max_re -= step_re;
	all->f.min_re -= step_re;
	display(all);
	mlx_put_image_to_window(all->g.mlx_ptr, all->g.win_ptr,
		all->g.img_ptr, 0, 0);
}

void	move_top(t_all *all)
{
	double	range_im;
	double	step_im;

	range_im = all->f.max_im - all->f.min_im;
	step_im = range_im * 0.05;
	all->f.max_im += step_im;
	all->f.min_im += step_im;
	display(all);
	mlx_put_image_to_window(all->g.mlx_ptr, all->g.win_ptr,
		all->g.img_ptr, 0, 0);
}

void	move_bot(t_all *all)
{
	double	range_im;
	double	step_im;

	range_im = all->f.max_im - all->f.min_im;
	step_im = range_im * 0.05;
	all->f.max_im -= step_im;
	all->f.min_im -= step_im;
	display(all);
	mlx_put_image_to_window(all->g.mlx_ptr, all->g.win_ptr,
		all->g.img_ptr, 0, 0);
}

void	finish_prog(t_all *all)
{
	mlx_destroy_image(all->g.mlx_ptr, all->g.img_ptr);
	mlx_destroy_window(all->g.mlx_ptr, all->g.win_ptr);
	mlx_destroy_display(all->g.mlx_ptr);
	free(all->g.mlx_ptr);
	exit (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 09:54:08 by msuter            #+#    #+#             */
/*   Updated: 2025/12/08 11:49:07 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	initialisation(t_all *all)
{
	all->f.max_iter = 100;
	all->f.min_re = -2;
	all->f.max_re = 1;
	all->f.min_im = -1.5;
	all->f.max_im = 1.5;
	all->f.julia_c_im = 0;
	all->f.julia_c_re = 0;
	all->z.ratio_zoom_in = 0.95;
	all->z.ratio_zoom_out = 1.05;
	all->z.global_zoom = 1;
	all->g.width = 1440;
	all->g.height = 810;
	all->f.move_x = 0;
	all->f.move_y = 0;
	all->z.initial_range_re = all->f.max_re - all->f.min_re;
	all->f.r_1 = 80;
	all->f.g_1 = 200;
	all->f.b_1 = 120;
	all->f.r_2 = 100;
	all->f.g_2 = 140;
	all->f.b_2 = 90;
}

static int	create_graphics(t_all *all)
{
	all->g.mlx_ptr = mlx_init ();
	if (!all->g.mlx_ptr)
		return (error (all, "erreur du pointeur mlx"));
	all->g.win_ptr = mlx_new_window (all->g.mlx_ptr, all->g.width, all->g.height, "fract_ol");
	if (!all->g.win_ptr)
		return (error (all, "erreur du pointeur window"));
	all->g.img_ptr = mlx_new_image (all->g.mlx_ptr, all->g.width, all->g.height);
	if (!all->g.img_ptr)
		return (error (all, "erreur du pointeur image"));
	all->g.addr = mlx_get_data_addr(all->g.img_ptr, &all->g.bytes_per_pixel,
			&all->g.len_line, &all->g.endian);
	if (!all->g.addr)
		return (error (all, "erreur lors de l'allocation du tab addr"));
	all->g.bytes_per_pixel = all->g.bytes_per_pixel / 8;
	return (0);
}

int	main(void)
{
	t_all	all;
	
	reset_value(&all);
	initialisation(&all);
	if (create_graphics(&all) == 1)
		return (1);
	if (display(&all) == 1)
		return (1);
	mlx_put_image_to_window(all.g.mlx_ptr, all.g.win_ptr, all.g.img_ptr, 0, 0);
	mlx_key_hook(all.g.win_ptr, which_button, &all);
	mlx_mouse_hook(all.g.win_ptr, which_mouse_button, &all);
	mlx_loop(all.g.mlx_ptr);
	return (0);
}

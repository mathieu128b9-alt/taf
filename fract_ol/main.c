/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 09:54:08 by msuter            #+#    #+#             */
/*   Updated: 2025/11/28 23:48:23 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

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

	all.g.width = 2560;
	all.g.height = 1540;
	reset_value(&all);
	if (create_graphics(&all) == 1)
		return (1);
	if (display(&all) == 1)
		return (1);
	mlx_put_image_to_window(all.g.mlx_ptr, all.g.win_ptr, all.g.img_ptr, 0, 0);
	mlx_loop(all.g.mlx_ptr);
	return (0);
}

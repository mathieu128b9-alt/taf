/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 09:54:08 by msuter            #+#    #+#             */
/*   Updated: 2025/11/28 15:03:24 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	create_graphics(t_all *all)
{
	all->g.mlx_ptr = mlx_init ();
	if (!all->g.mlx_ptr)
		return (error (all, "erreur du pointeur mlx"));
	all->g.win_ptr = mlx_new_window (all->g.mlx_ptr, 800, 600, "fract_ol");
	if (!all->g.win_ptr)
		return (error (all, "erreur du pointeur window"));
	all->g.img_ptr = mlx_new_image (all->g.mlx_ptr, 800, 600);
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
	if (create_graphics(&all) == 1)
		return (1);
	return (0);
}

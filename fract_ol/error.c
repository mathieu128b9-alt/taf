/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:37:38 by msuter            #+#    #+#             */
/*   Updated: 2025/11/28 15:01:59 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	reset_value(t_all *all)
{
	all->g.img_ptr = NULL;
	all->g.win_ptr = NULL;
	all->g.mlx_ptr = NULL;
	all->g.addr = NULL;
	all->g.bytes_per_pixel = 0;
	all->g.len_line = 0;
	all->g.endian = 0;
}

static void	cleanup_graphics(t_all *all)
{
	if (all->g.img_ptr != NULL)
	{
		mlx_destroy_image(all->g.mlx_ptr, all->g.img_ptr);
		all->g.img_ptr = NULL;
	}
	if (all->g.win_ptr != NULL)
	{
		mlx_destroy_window(all->g.mlx_ptr, all->g.win_ptr);
		all->g.win_ptr = NULL;
	}
	if (all->g.mlx_ptr != NULL)
	{
		mlx_destroy_display(all->g.mlx_ptr);
		free(all->g.mlx_ptr);
		all->g.mlx_ptr = NULL;
	}
	all->g.addr = NULL;
	all->g.bytes_per_pixel = 0;
	all->g.len_line = 0;
	all->g.endian = 0;
}

int	error(t_all *all, char *msg)
{
	cleanup_graphics(all);
	ft_putstr_fd(msg, 2);
	return (1);
}

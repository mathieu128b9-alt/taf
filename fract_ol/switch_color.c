/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 23:31:43 by msuter            #+#    #+#             */
/*   Updated: 2025/12/06 00:23:53 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	switch_color(t_all *all, int keycode)
{
	if (keycode == 49)
	{
		all->f.color_r = 210;
		all->f.color_b = 100;
		all->f.color_b = 220;
	}
	else if (keycode == 50)
	{
		all->f.color_r = 230;
		all->f.color_b = 110;
		all->f.color_b = 50;
	}
	else if (keycode == 51)
	{
		all->f.color_r = 60;
		all->f.color_b = 200;
		all->f.color_b = 120;
	}
	else if (keycode == 52)
	{
		all->f.color_r = 210;
		all->f.color_b = 100;
		all->f.color_b = 220;
	}
	display(all);
	mlx_put_image_to_window(all->g.mlx_ptr, all->g.win_ptr, all->g.img_ptr, 0, 0);
}
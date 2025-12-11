/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 23:31:43 by msuter            #+#    #+#             */
/*   Updated: 2025/12/11 08:46:35 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	switch_color_2(t_all *all, int keycode)
{
	if (keycode == 51)
	{
		all->f.r_1 = 180;
		all->f.g_1 = 120;
		all->f.b_1 = 200;
		all->f.r_2 = 90;
		all->f.g_2 = 140;
		all->f.b_2 = 160;
	}
	else if (keycode == 52)
	{
		all->f.r_1 = 220;
		all->f.g_1 = 100;
		all->f.b_1 = 40;
		all->f.r_2 = 140;
		all->f.g_2 = 90;
		all->f.b_2 = 60;
	}
}

void	switch_color(t_all *all, int keycode)
{
	if (keycode == 49)
	{
		all->f.r_1 = 80;
		all->f.g_1 = 200;
		all->f.b_1 = 120;
		all->f.r_2 = 100;
		all->f.g_2 = 140;
		all->f.b_2 = 90;
	}
	else if (keycode == 50)
	{
		all->f.r_1 = 140;
		all->f.g_1 = 140;
		all->f.b_1 = 30;
		all->f.r_2 = 100;
		all->f.g_2 = 100;
		all->f.b_2 = 60;
	}
	else if (keycode >= 51 && keycode <= 52)
		switch_color_2(all, keycode);
	display(all);
	mlx_put_image_to_window(all->g.mlx_ptr,
		all->g.win_ptr, all->g.img_ptr, 0, 0);
}

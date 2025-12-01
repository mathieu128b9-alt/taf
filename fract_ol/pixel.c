/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:02:37 by msuter            #+#    #+#             */
/*   Updated: 2025/12/01 03:49:57 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mandelbroot(int x, int y, t_all *all)
{
	int	i;
	double	temp;
	double	z_re;
	double	z_im;
	//all->f.max_iter = 500;
	//all->f.min_re = -2;
	//all->f.max_re = 1;
	//all->f.min_im = -1.5;
	//all->f.max_im = 1.5;
	i = 0;
	z_re = 0;
	z_im = 0;
	all->f.c_re = (((all->f.max_re - all->f.min_re)
				/all->g.width) * x) + all->f.min_re;
	all->f.c_im = all->f.max_im - (((all->f.max_im - all->f.min_im)
				/ all->g.height) * y);
	while (i < all->f.max_iter)
	{
		temp = z_re;
		z_re = ((z_re * z_re) - (z_im * z_im)) + all->f.c_re;
		z_im = ((2 * temp) * z_im) + all->f.c_im;
		if ((z_im * z_im) + (z_re * z_re) > 4)
			return (0);
		i++;
	}
	return (i);
}

static int	is_in_window(t_all *all, int x, int y)
{
	if (x >= 0 && x < all->g.width)
		if (y >= 0 && y < all->g.height)
			return (0);
	return (1);
}

void	color_pixel(t_all *all, int offset_total, int i)
{
	if (i != 0)
	{
		all->g.addr[offset_total] = i * 2;
		all->g.addr[offset_total + 1] = i * 3;
		all->g.addr[offset_total + 2] = 100 + i * 5;
	}
	else
	{
		all->g.addr[offset_total] = 255;
		all->g.addr[offset_total + 1] = 255;
		all->g.addr[offset_total + 2] = 255;
	}
}

static int	put_pixel(t_all *all, int x, int y)
{
	int	offset_y;
	int	offset_x;
	int	offset_total;
	int	i;

	if (is_in_window(all, x, y) == 1)
		return (1);
	offset_y = y * all->g.len_line;
	offset_x = x * all->g.bytes_per_pixel;
	offset_total = offset_x + offset_y;
	i = mandelbroot(x, y, all);
	color_pixel(all, offset_total, i);
	return (0);
}

int	display(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->g.height)
	{
		x = 0;
		while (x < all->g.width)
		{			
			if (put_pixel(all, x, y) == 1)
			{
				error(all, "erreur d'affichage d'un pixel");
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

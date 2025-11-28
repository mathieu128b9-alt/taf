/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:02:37 by msuter            #+#    #+#             */
/*   Updated: 2025/11/28 22:40:38 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	is_in_window(t_all *all, int x, int y)
{
	if (x >= 0 && x < all->g.width)
		if(y >= 0 && y < all->g.height)
			return (0);
	return (1);
}

static int	put_pixel(t_all *all, int x, int y)
{
	int	offset_y;
	int	offset_x;
	int	offset_total;
	
	if (is_in_window(all, x, y) == 1)
		return (1);
	offset_y = y * all->g.len_line;
	offset_x = x * all->g.bytes_per_pixel;
	offset_total = offset_x + offset_y;
	all->g.addr[offset_total] = 255;
	all->g.addr[offset_total + 1] = 255;
	all->g.addr[offset_total + 2] = 255;
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
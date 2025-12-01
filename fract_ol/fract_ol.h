/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:22:52 by msuter            #+#    #+#             */
/*   Updated: 2025/12/01 02:02:31 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
#define FRACT_OL_H

#include <math.h>
#include "minilibx/mlx.h"
#include "libft/libft.h"

typedef struct t_graphics
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bytes_per_pixel;
	int		len_line;
	int		endian;
	int		width;
	int		height;
} t_graphics;

typedef struct t_fractal
{
	int		fractal_type;
	double	zoom;
	double	c_im;
	double	c_re;
	double	max_re;
	double	min_re;
	double	max_im;
	double	min_im;
	int		max_iter;
	double	julia_c_re;
	double	julia_c_im;

} t_fractal;

typedef struct t_all
{
	t_graphics g;
	t_fractal f;

} t_all;

int		error(t_all *all, char *msg);
void	reset_value(t_all *all);
int		display(t_all *all);

#endif

//cc -Wall -Wextra -Werror -Iminilibx -Ilibft -Lminilibx -Llibft main.c error.c minilibx/libmlx_Linux.a libft/libft.a -lXext -lX11 -lm -lz
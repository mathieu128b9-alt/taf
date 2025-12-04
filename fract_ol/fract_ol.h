/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:22:52 by msuter            #+#    #+#             */
/*   Updated: 2025/12/04 19:45:06 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <math.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "stdio.h"
# include <pthread.h>

# define KEY_PLUS 61
# define N_THREAD 8


typedef struct t_zoom
{
	double	global_zoom;
	double	ratio_zoom;
	double	center_re;
	double	center_im;
	double	current_range_re;
	double	half_re;
	double	half_im;
	int		mouse_x;
	int		mouse_y;
	double	mouse_re;
	double	mouse_im;
	double	scale_re;
	double	scale_im;
	double	initial_range_re;

}	t_zoom;

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

}	t_graphics;

typedef struct t_fractal
{
	int		fractal_type;
	double	max_re;
	double	min_re;
	double	max_im;
	double	min_im;
	int		max_iter;
	double	julia_c_re;
	double	julia_c_im;
	double	move_x;
	double	move_y;

}	t_fractal;

typedef struct t_all
{
	t_graphics	g;
	t_fractal	f;
	t_zoom		z;

}	t_all;

typedef struct t_thread
{
	int		thrd_y_srt;
	int		thrd_y_end;
	t_all 	*all;

}	t_thread;

int		error(t_all *all, char *msg);
void	reset_value(t_all *all);
int		display(t_all *all);
int		which_button(int keycode, void *param);
int		put_pixel(t_all *all, int x, int y);
void	creation_thread(pthread_t *thread_id, t_thread *thread_stk);


#endif

//cc -Wall -Wextra -Werror -Iminilibx -Ilibft -Lminilibx -Llibft main.c error.c minilibx/libmlx_Linux.a libft/libft.a -lXext -lX11 -lm -lz
	//all->g.addr[offset_total] = 9 * (1 - t) * (t * t * t) * 255;
	//	all->g.addr[offset_total + 1] = 15 * (1 - t) * (1 - t) * (t * t) * 255;
	//	all->g.addr[offset_total + 2] = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
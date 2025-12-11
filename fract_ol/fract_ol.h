/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:22:52 by msuter            #+#    #+#             */
/*   Updated: 2025/12/11 08:10:18 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <math.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "stdio.h"
# include <pthread.h>

# define KEY_ZOOM 5
# define KEY_UNZOOM 4
# define KEY_MOINS 45
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_TOP 65362
# define KEY_BOT 65364
# define N_THREAD 8
# define N_PI 3.14159265358979323846
# define KEY_J 106


typedef struct t_zoom
{
	double	global_zoom;
	double	ratio_zoom_in;
	double	ratio_zoom_out;
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
	double	r_1;
	double	g_1;
	double	b_1;
	double	r_2;
	double	g_2;
	double	b_2;
	int		mode;
	int		julia_fix;
	double	phoenix_p_re;
	double	phoenix_p_im;

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
int		which_mouse_button(int keycode, int x, int y, void *param);
void	move_bot(t_all *all);
void	move_top(t_all *all);
void	move_left(t_all *all);
void	move_right(t_all *all);
void	finish_prog(t_all *all);
void	switch_color(t_all *all, int param);
double	julia(t_all *all, double i, double mandel_c_re, double mandel_c_im);
int		mouse_motion(int x, int y, void *param);
double	phoenix_julia(t_all *all, double iter, double z_re, double z_im);

#endif
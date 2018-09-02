/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:06:16 by abiriuk           #+#    #+#             */
/*   Updated: 2018/08/31 17:59:06 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "stdlib.h"

# define HOR 1200
# define VER 1200
# define LARGE 50
# define HEIGHT 15
# define GRAD 30
# define RAD GRAD*M_PI/180
# define MOVE 10
# define ZOOM 1.1

typedef	struct		s_pixel
{
	double			x;
	double			y;
	double			z;
	struct s_pixel	*next;
	struct s_pixel	*down;
}					t_pixel;

typedef struct		s_global
{
	t_pixel			*head;
	struct s_global	*next;
}					t_global;

typedef	struct		s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_win;

typedef struct		s_all
{
	t_global		*head;
	t_win			win_str;
	t_pixel			move;
	t_global		*copy;
}					t_all;

typedef	struct		s_ln
{
	double			x1;
	double			y1;
	int				x2;
	int				y2;
}					t_ln;

typedef struct		s_leng
{
	int				dx;
	int				dy;
	int				lengthx;
	int				lengthy;
}					t_leng;

t_pixel				*check(char **mass, int y);
t_global			*new_global_node(t_pixel *head);
void				error_msg(char *str);
void				ft_link(t_global *current, t_global *down);
void				print_list(t_all *all);
int					exit_x(void *par);
void				line(t_all *all, t_ln *ln);
int					exit_esc(int keycode, void *param);
void				cage(t_all *all);
void				for_each(t_all *all, void (*f)(t_pixel *, void *),
						void *shift_c);
void				coordinates(t_all *all, t_pixel *min, t_pixel *max);
void				centering(t_all *all);
void				shift(t_pixel *pixel, void *shift_c);
void				large(t_pixel *pixel, void *ptr);
int					move(int keycode, void *param);
void				redraw(t_all *all);
void				horizontal(t_all *all);
void				vertical(t_all *all);
void				move_right(t_pixel *pixel, void *ptr);
void				move_left(t_pixel *pixel, void *ptr);
void				move_up(t_pixel *pixel, void *ptr);
void				move_down(t_pixel *pixel, void *ptr);
double				min_x(t_all *all);
double				min_y(t_all *all);
double				max_x(t_all *all);
double				max_y(t_all *all);
void				increase(t_pixel *pixel, void *ptr);
void				decrease(t_pixel *pixel, void *ptr);
void				move_xy_rot(t_all *all, int keycode);
void				move_z_rot(t_all *all, int keycode);
void				view(t_all *all);
void				x_rotation_up(t_pixel *pixel, void *ptr);
void				y_rotation_right(t_pixel *pixel, void *ptr);
void				move_xy_move(t_all *all, int keycode);
void				shift_move(t_pixel *pixel, void *ptr);
void				cp_glist(t_all *all);
t_global			*copy_glist(t_global *head);

#endif

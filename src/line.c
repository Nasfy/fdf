/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:05:16 by abiriuk           #+#    #+#             */
/*   Updated: 2018/08/31 17:58:10 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "fdf.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define MAX(x, y) ( x > y ? x : y)
#define ROUNDF(x) floor(x + 0.5f)

int		exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

int		exit_esc(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
		exit(1);
	return (0);
}

void	if_func(t_leng *leng, int length, t_ln *line, t_all *all)
{
	int		x;
	float	y;
	int		d;

	x = line->x1;
	y = line->y1;
	d = -leng->lengthx;
	length++;
	while (length--)
	{
		mlx_pixel_put(all->win_str.mlx_ptr, all->win_str.win_ptr, x,
				ROUNDF(y), 0xFFFFFF);
		x += leng->dx;
		d += 2 * leng->lengthy;
		if (d > 0)
		{
			d -= 2 * leng->lengthx;
			y += leng->dy;
		}
	}
}

void	else_func(t_all *all, t_ln *line, int length, t_leng *leng)
{
	float	x;
	int		y;
	int		d;

	x = line->x1;
	y = line->y1;
	d = -leng->lengthy;
	length++;
	while (length--)
	{
		mlx_pixel_put(all->win_str.mlx_ptr, all->win_str.win_ptr,
				ROUNDF(x), y, 0xFFFFFF);
		y += leng->dy;
		d += 2 * leng->lengthx;
		if (d > 0)
		{
			d -= 2 * leng->lengthy;
			x += leng->dx;
		}
	}
}

void	line(t_all *all, t_ln *ln)
{
	t_leng		leng;
	int			length;

	leng.lengthx = ABS(ln->x2 - ln->x1);
	leng.lengthy = ABS(ln->y2 - ln->y1);
	leng.dx = (ln->x2 - ln->x1 >= 0 ? 1 : -1);
	leng.dy = (ln->y2 - ln->y1 >= 0 ? 1 : -1);
	if (leng.lengthx == leng.lengthy && leng.lengthx == 0)
		length = 0;
	else
		length = MAX(leng.lengthx, leng.lengthy);
	if (length == 0)
		mlx_pixel_put(all->win_str.mlx_ptr, all->win_str.win_ptr,
				ln->x1, ln->y1, 0xFFFFFF);
	if (leng.lengthy <= leng.lengthx)
		if_func(&leng, length, ln, all);
	else
		else_func(all, ln, length, &leng);
}

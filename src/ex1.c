/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:05:16 by abiriuk           #+#    #+#             */
/*   Updated: 2018/08/07 16:20:07 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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

void	line(t_all *all, int x1, int y1, int x2, int y2)
{
	int	dx = (x2 - x1 >= 0 ? 1 : -1);
	int dy = (y2 - y1 >= 0 ? 1 : -1);
	
	int	lengthX = ABS(x2 - x1);
	int	lengthY = ABS(y2 - y1);
	int length;

	if (lengthX == lengthY && lengthX == 0)
		length = 0;
	else
		length = MAX(lengthX, lengthY);
	if (length == 0)
		mlx_pixel_put(all->win_str.mlx_ptr, all->win_str.win_ptr, x1, y1, 0xFFFFFF);
	if (lengthY <= lengthX)
	{
		int x = x1;
		float y = y1;
		int d = -lengthX;
		
		length++;
		while (length--)
		{
			mlx_pixel_put(all->win_str.mlx_ptr, all->win_str.win_ptr, x, ROUNDF(y), 0xFFFFFF);
			x += dx;
			d += 2 * lengthY;
			if (d > 0)
			{
				d -= 2 * lengthX;
				y += dy;
			}
		}
	}
	else
	{
		float x = x1;
		int y = y1;
		int d = - lengthY;	

		length++;
		while (length--)
		{
			mlx_pixel_put(all->win_str.mlx_ptr, all->win_str.win_ptr, ROUNDF(x), y, 0xFFFFFF);
			y += dy;
			d += 2 * lengthX;
			if (d > 0)
			{
				d -= 2 * lengthY;
				x += dx;
			}
		}
	}
}
/*
{
	t_win	win_str;

	win_str.mlx_ptr = mlx_init();
	win_str.win_ptr = mlx_new_window(win_str.mlx_ptr, 500, 500, "banana");	//(откр окно 500на500 и назв банана)//
	mlx_pixel_put(win_str.mlx_ptr, win_str.win_ptr, 250, 250, 0xFF0000);	//(ставит точку в центре)//
	mlx_hook(win_str.win_ptr, 17, 1L << 17, exit_x, (void *)0);				//чтобы выходить крестиком с окна//
	mlx_key_hook(win_str.win_ptr, exit_esc, (void *)0);						//зарыть окно  esc //

}*/

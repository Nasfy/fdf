/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xy_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 17:29:02 by abiriuk           #+#    #+#             */
/*   Updated: 2018/08/31 17:42:53 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdlib.h"

void	x_rotation_up(t_pixel *pixel, void *ptr)
{
	double y;
	double z;

	y = pixel->y;
	z = pixel->z;
	if (ptr)
		;
	pixel->y = y * cos(RAD) - z * sin(RAD);
	pixel->z = y * sin(RAD) + z * cos(RAD);
}

void	x_rotation_down(t_pixel *pixel, void *ptr)
{
	double y;
	double z;

	y = pixel->y;
	z = pixel->z;
	if (ptr)
		;
	pixel->y = y * cos(RAD) + z * sin(RAD);
	pixel->z = -y * sin(RAD) + z * cos(RAD);
}

void	y_rotation_right(t_pixel *pixel, void *ptr)
{
	double z;
	double x;

	z = pixel->z;
	x = pixel->x;
	if (ptr)
		;
	pixel->z = z * cos(RAD) - x * sin(RAD);
	pixel->x = z * sin(RAD) + x * cos(RAD);
}

void	y_rotation_left(t_pixel *pixel, void *ptr)
{
	double z;
	double x;

	z = pixel->z;
	x = pixel->x;
	if (ptr)
		;
	pixel->z = z * cos(RAD) + x * sin(RAD);
	pixel->x = -z * sin(RAD) + x * cos(RAD);
}

void	move_xy_rot(t_all *all, int keycode)
{
	if (keycode == 91)
		for_each(all, x_rotation_up, NULL);
	else if (keycode == 84)
		for_each(all, x_rotation_down, NULL);
	else if (keycode == 88)
		for_each(all, y_rotation_right, NULL);
	else if (keycode == 86)
		for_each(all, y_rotation_left, NULL);
	centering(all);
	for_each(all, shift_move, &all->move);
}

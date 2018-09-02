/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 20:07:37 by abiriuk           #+#    #+#             */
/*   Updated: 2018/08/31 17:43:10 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdlib.h"

void	z_rotation_right(t_pixel *pixel, void *ptr)
{
	double	x;
	double	y;

	x = pixel->x;
	y = pixel->y;
	if (ptr)
		;
	pixel->x = x * cos(RAD) - y * sin(RAD);
	pixel->y = x * sin(RAD) + y * cos(RAD);
}

void	z_rotation_left(t_pixel *pixel, void *ptr)
{
	double x;
	double y;

	x = pixel->x;
	y = pixel->y;
	if (ptr)
		;
	pixel->x = x * cos(RAD) + y * sin(RAD);
	pixel->y = -x * sin(RAD) + y * cos(RAD);
}

void	move_z_rot(t_all *all, int keycode)
{
	if (keycode == 85)
	{
		for_each(all, z_rotation_right, NULL);
		centering(all);
	}
	else if (keycode == 83)
	{
		for_each(all, z_rotation_left, NULL);
		centering(all);
	}
}

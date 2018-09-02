/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 16:42:35 by abiriuk           #+#    #+#             */
/*   Updated: 2018/08/31 17:42:22 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdlib.h"

void	shift_move(t_pixel *pixel, void *ptr)
{
	t_pixel	*move;

	move = (t_pixel *)ptr;
	pixel->x = pixel->x + move->x;
	pixel->y = pixel->y + move->y;
}

int		move(int keycode, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	move_xy_move(all, keycode);
	if (keycode == 8)
		cp_glist(all);
	else if (keycode == 69)
	{
		for_each(all, increase, NULL);
		centering(all);
		for_each(all, shift_move, &all->move);
	}
	else if (keycode == 78)
	{
		for_each(all, decrease, NULL);
		centering(all);
		for_each(all, shift_move, &all->move);
	}
	else
	{
		move_xy_rot(all, keycode);
		move_z_rot(all, keycode);
	}
	redraw(all);
	return (0);
}

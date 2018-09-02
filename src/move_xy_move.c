/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_xy_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:24:35 by abiriuk           #+#    #+#             */
/*   Updated: 2018/08/07 15:58:21 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_xy_move(t_all *all, int keycode)
{
	if (keycode == 124)
	{
		for_each(all, move_right, NULL);
		all->move.x += MOVE;
	}
	else if (keycode == 123)
	{
		for_each(all, move_left, NULL);
		all->move.x -= MOVE;
	}
	else if (keycode == 126)
	{
		for_each(all, move_up, NULL);
		all->move.y -= MOVE;
	}
	else if (keycode == 125)
	{
		for_each(all, move_down, NULL);
		all->move.y += MOVE;
	}
}

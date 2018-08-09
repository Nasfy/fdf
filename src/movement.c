/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 17:41:43 by abiriuk           #+#    #+#             */
/*   Updated: 2018/08/09 18:26:27 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"
#include "mlx.h"

void	move_right(t_pixel *pixel, void *ptr)
{
	if (ptr)
		;
	pixel->x = pixel->x + MOVE;
}

void	move_left(t_pixel *pixel, void *ptr)
{
	if (ptr)
		;
	pixel->x = pixel->x - MOVE;
}

void	move_up(t_pixel *pixel, void *ptr)
{
	if (ptr)
		;
	pixel->y = pixel->y - MOVE;
}

void	move_down(t_pixel *pixel, void *ptr)
{
	if (ptr)
		;
	pixel->y = pixel->y + MOVE;
}

void	redraw(t_all *all)
{
	mlx_clear_window(all->win_str.mlx_ptr, all->win_str.win_ptr);
	horizontal(all);
	vertical(all);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:33:11 by abiriuk           #+#    #+#             */
/*   Updated: 2018/08/07 16:56:42 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void	coordinates(t_all *all, t_pixel *min, t_pixel *max)
{
	min->x = min_x(all);
	min->y = min_y(all);
	max->x = max_x(all);
	max->y = max_y(all);
}

void	large(t_pixel *pixel, void *ptr)
{
	if (ptr)
		;
	pixel->x = pixel->x * LARGE;
	pixel->y = pixel->y * LARGE;
	pixel->z = pixel->z * HEIGHT;
}

void	centering(t_all *all)
{
	t_pixel		max;
	t_pixel		min;
	t_pixel		shift_c;

	coordinates(all, &min, &max);
	shift_c.x = (HOR - max.x + min.x) / 2 - min.x;
	shift_c.y = (VER - max.y + min.y) / 2 - min.y;
	for_each(all, shift, &shift_c);
}

void	shift(t_pixel *pixel, void *shift_c)
{
	t_pixel		*shift_centr;

	shift_centr = (t_pixel *)shift_c;
	pixel->x = pixel->x + shift_centr->x;
	pixel->y = pixel->y + shift_centr->y;
}

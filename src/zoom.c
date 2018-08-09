/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 20:12:31 by abiriuk           #+#    #+#             */
/*   Updated: 2018/08/09 18:27:14 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	increase(t_pixel *pixel, void *ptr)
{
	if (ptr)
		;
	pixel->x = pixel->x * ZOOM;
	pixel->y = pixel->y * ZOOM;
}

void	decrease(t_pixel *pixel, void *ptr)
{
	if (ptr)
		;
	pixel->x = pixel->x / ZOOM;
	pixel->y = pixel->y / ZOOM;
}

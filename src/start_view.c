/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 18:04:03 by abiriuk           #+#    #+#             */
/*   Updated: 2018/08/09 18:14:10 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	view(t_all *all)
{
	for_each(all, x_rotation_up, NULL);
//	for_each(all, y_rotation_right, NULL);
	for_each(all, y_rotation_right, NULL);
	centering(all);
	horizontal(all);
	vertical(all);
}

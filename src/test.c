/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 19:11:46 by abiriuk           #+#    #+#             */
/*   Updated: 2018/08/31 17:42:00 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "stdlib.h"

void	horizontal(t_all *all)
{
	t_global	*tmp;
	t_pixel		*che;
	t_ln		ln;

	tmp = all->head;
	while (tmp)
	{
		che = tmp->head;
		while (che->next)
		{
			ln.x1 = che->x;
			ln.y1 = che->y;
			ln.x2 = che->next->x;
			ln.y2 = che->next->y;
			line(all, &ln);
			che = che->next;
		}
		tmp = tmp->next;
	}
}

void	vertical(t_all *all)
{
	t_pixel		*fir;
	t_pixel		*sec;
	t_global	*tmp;
	t_ln		ln;

	tmp = all->head;
	while (tmp->next)
	{
		fir = tmp->head;
		sec = tmp->next->head;
		while (fir)
		{
			ln.x1 = fir->x;
			ln.y1 = fir->y;
			ln.x2 = sec->x;
			ln.y2 = sec->y;
			line(all, &ln);
			fir = fir->next;
			sec = sec->next;
		}
		tmp = tmp->next;
	}
}

void	cage(t_all *all)
{
	t_global	*tmp;

	tmp = all->head;
	all->win_str.mlx_ptr = mlx_init();
	all->win_str.win_ptr = mlx_new_window(all->win_str.mlx_ptr,
			HOR, VER, "fdf");
	mlx_hook(all->win_str.win_ptr, 17, 1L << 17, exit_x, (void *)0);
	mlx_key_hook(all->win_str.win_ptr, exit_esc, (void *)0);
	for_each(all, large, NULL);
	centering(all);
	view(all);
	all->copy = copy_glist(all->head);
	mlx_hook(all->win_str.win_ptr, 2, 1L << 0, move, all);
	mlx_loop(all->win_str.mlx_ptr);
}

void	for_each(t_all *all, void (*f)(t_pixel *, void *), void *shift_c)
{
	t_global	*tmp;
	t_pixel		*cur;

	tmp = all->head;
	while (tmp)
	{
		cur = tmp->head;
		while (cur)
		{
			(f)(cur, shift_c);
			cur = cur->next;
		}
		tmp = tmp->next;
	}
}

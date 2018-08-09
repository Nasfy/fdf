/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 19:11:46 by abiriuk           #+#    #+#             */
/*   Updated: 2018/08/09 17:57:10 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdio.h>

void	print_list(t_all *all)
{
	t_pixel		*elem;
	t_global	*tmp;

	tmp = all->head;
	while (tmp)
	{
		elem = tmp->head;
		while (elem)
		{
			printf("%4.0f", elem->y);
			elem = elem->next;
		}
		printf("\n");
		tmp = tmp->next;
	}
}

void	horizontal(t_all *all)
{
	t_global	*tmp;
	t_pixel		*che;

	tmp = all->head;
	while (tmp)
	{
		che = tmp->head;
		while (che->next)
		{
			line(all, che->x, che->y, che->next->x, che->next->y);
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

	tmp = all->head;
	while (tmp->next)
	{
		fir = tmp->head;
		sec = tmp->next->head;
		while (fir)
		{
			line(all, fir->x, fir->y, sec->x, sec->y);
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
	all->win_str.win_ptr = mlx_new_window(all->win_str.mlx_ptr, HOR, VER, "fdf");
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

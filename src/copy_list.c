/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:04:30 by abiriuk           #+#    #+#             */
/*   Updated: 2018/08/31 17:33:04 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdlib.h"

t_pixel		*copy_list(t_pixel *pixel_old)
{
	t_pixel		*pixel_new;
	t_pixel		*tail;
	t_pixel		*tmp;

	pixel_new = NULL;
	while (pixel_old != NULL)
	{
		tail = (t_pixel *)malloc(sizeof(t_pixel));
		tail->x = pixel_old->x;
		tail->y = pixel_old->y;
		tail->z = pixel_old->z;
		tail->next = NULL;
		if (pixel_new == NULL)
		{
			pixel_new = tail;
			tmp = tail;
		}
		else
		{
			tmp->next = tail;
			tmp = tmp->next;
		}
		pixel_old = pixel_old->next;
	}
	return (pixel_new);
}

t_global	*copy_glist(t_global *head)
{
	t_global	*tail;
	t_global	*node_new;
	t_global	*node_old;

	node_old = head;
	node_new = NULL;
	while (node_old != NULL)
	{
		if (node_new == NULL)
		{
			node_new = (t_global *)malloc(sizeof(t_global));
			node_new->head = copy_list(node_old->head);
			tail = node_new;
		}
		else
		{
			tail->next = (t_global *)malloc(sizeof(t_global));
			tail = tail->next;
			tail->head = copy_list(node_old->head);
			tail->next = NULL;
		}
		node_old = node_old->next;
	}
	return (node_new);
}

void		cp_list(t_global *node_old, t_global *node_new)
{
	t_pixel		*pixel_new;
	t_pixel		*pixel_old;

	pixel_old = node_old->head;
	pixel_new = node_new->head;
	while (pixel_old != NULL)
	{
		pixel_new->x = pixel_old->x;
		pixel_new->y = pixel_old->y;
		pixel_new->z = pixel_old->z;
		pixel_old = pixel_old->next;
		pixel_new = pixel_new->next;
	}
}

void		cp_glist(t_all *all)
{
	t_global	*node_new;
	t_global	*node_old;

	all->move.y = 0;
	all->move.x = 0;
	node_old = all->copy;
	node_new = all->head;
	while (node_old != NULL)
	{
		cp_list(node_old, node_new);
		node_old = node_old->next;
		node_new = node_new->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:00:27 by abiriuk           #+#    #+#             */
/*   Updated: 2018/08/07 16:22:35 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		min_x(t_all *all)
{
	t_global	*head;
	t_pixel		*tmp;
	double		min_x;

	head = all->head;
	min_x = head->head->x;
	while (head)
	{
		tmp = head->head;
		while (tmp)
		{
			if (min_x > tmp->x)
				min_x = tmp->x;
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (min_x);
}

double		min_y(t_all *all)
{
	t_global	*head;
	t_pixel		*tmp;
	double		min_y;

	head = all->head;
	min_y = head->head->y;
	while (head)
	{
		tmp = head->head;
		while (tmp)
		{
			if (min_y > tmp->y)
				min_y = tmp->y;
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (min_y);
}

double		max_x(t_all *all)
{
	t_global	*head;
	t_pixel		*tmp;
	double		max_x;

	head = all->head;
	max_x = head->head->x;
	while (head)
	{
		tmp = head->head;
		while (tmp)
		{
			if (max_x < tmp->x)
				max_x = tmp->x;
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (max_x);
}

double		max_y(t_all *all)
{
	t_global	*head;
	t_pixel		*tmp;
	double		max_y;

	head = all->head;
	max_y = head->head->y;
	while (head)
	{
		tmp = head->head;
		while (tmp)
		{
			if (max_y < tmp->y)
				max_y = tmp->y;
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (max_y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:28:15 by abiriuk           #+#    #+#             */
/*   Updated: 2018/08/08 18:42:10 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_global	*new_global_node(t_pixel *head)
{
	t_global	*node;

	node = (t_global *)malloc(sizeof(t_global));
	if (node == NULL)
		error_msg("Error creating a new node.\n");
	node->head = head;
	node->next = NULL;
	return (node);
}

void		ft_link(t_global *current, t_global *down)
{
	t_pixel		*tmp_up;
	t_pixel		*tmp_down;

	tmp_up = current->head;
	tmp_down = down->head;
	while (tmp_up)
	{
		tmp_up->down = tmp_down;
		tmp_up = tmp_up->next;
		tmp_down = tmp_down->next;
	}
	current->next = down;
}

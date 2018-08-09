/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:46:24 by abiriuk           #+#    #+#             */
/*   Updated: 2018/08/08 18:42:13 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fdf.h"
#include <stdio.h>
#include "./libft/libft.h"
#include <stdlib.h>

t_pixel		*creat_node(int x, int y, int z)
{
	t_pixel	*new_node;

	new_node = (t_pixel *)malloc(sizeof(t_pixel) + 1);
	if (new_node == NULL)
		error_msg("Error creating a new node.\n");
	new_node->x = x;
	new_node->y = y;
	new_node->z = z;
	new_node->next = NULL;
	new_node->down = NULL;
	return (new_node);
}

t_pixel		*check(char **mass, int y)
{
	int		i;
	t_pixel	*head;
	t_pixel	*tmp;
	t_pixel	*cursor;

	head = NULL;
	i = 0;
	while (mass[i])
	{
		tmp = creat_node(i, y, ft_atoi(mass[i]));
		if (head == NULL)
		{
			head = tmp;
			cursor = head;
		}
		else
		{
			cursor->next = tmp;
			cursor = tmp;
		}
		i++;
	}
	printf("%d\n", y);
	return (head);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:46:29 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/28 20:11:29 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lst;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		lst->content = 0;
		lst->content_size = 0;
	}
	else
	{
		if (!(lst->content = malloc(content_size)))
		{
			free(lst);
			return (0);
		}
		else
		{
			ft_memcpy(lst->content, content, content_size);
			lst->content_size = content_size;
		}
	}
	lst->next = NULL;
	return (lst);
}

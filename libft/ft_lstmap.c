/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 13:56:25 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/28 20:10:44 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*buf;

	if (f == 0)
		return (0);
	new = NULL;
	while (lst != NULL)
	{
		buf = f(lst);
		if (buf == NULL)
		{
			ft_lstdel(&new, ft_del_cont);
			return (0);
		}
		lst = lst->next;
		ft_lstadd_rev(&new, buf);
	}
	return (new);
}

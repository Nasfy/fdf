/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:35:35 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/26 13:26:52 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*new;
	t_list	*buf;

	if (alst == NULL)
		return ;
	if (*alst == NULL || (del) == NULL)
		return ;
	buf = NULL;
	new = *alst;
	while (new)
	{
		buf = new;
		new = new->next;
		ft_lstdelone(&buf, del);
	}
	*alst = NULL;
}

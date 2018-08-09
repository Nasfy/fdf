/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:07:55 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/28 20:07:28 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstsplit(char const *s, char c)
{
	size_t	i;
	size_t	nc;
	size_t	p;
	t_list	*buf;

	buf = NULL;
	i = 0;
	nc = 0;
	if (s == 0)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		p = i;
		while (s[i + nc] != c && s[i + nc] != '\0')
			ncol++;
		i += nc;
		if (!ft_lstadd_rev(&buf, ft_lstnew(ft_strsub(s, p, nc), ncol + 1)))
		{
			ft_lstdel(&buf, ft_del_cont);
			return (0);
		}
	}
	return (buf);
}

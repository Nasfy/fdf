/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:30:53 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/29 20:01:33 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace_elem(const char *str, char old, char new)
{
	int		i;
	char	*s1;

	if (str == 0)
		return (0);
	i = 0;
	s1 = ft_strdup(str);
	while (s1[i])
	{
		if (s1[i] == old)
			s1[i] = new;
		i++;
	}
	return (s1);
}

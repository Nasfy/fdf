/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:28:28 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/09 18:24:34 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;
	char	*n;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
		{
			n = &((char *)str)[i];
			return (n);
		}
		i++;
	}
	if (ch == '\0')
		return (&((char *)str)[i]);
	return (0);
}

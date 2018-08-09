/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:38:16 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/11 17:05:12 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*q;
	size_t	len;

	i = 0;
	if (s == 0 || (f) == 0)
		return (0);
	len = ft_strlen(s);
	q = (char *)malloc(sizeof(char) * (len + 1));
	if (q == 0)
		return (0);
	while (s[i] != '\0')
	{
		q[i] = f(s[i]);
		i++;
	}
	q[i] = '\0';
	return (q);
}

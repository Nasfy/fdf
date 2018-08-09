/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:09:35 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/20 17:07:01 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s2, const char *s1, size_t len)
{
	size_t	i;
	size_t	u;
	size_t	o;

	i = 0;
	u = 0;
	o = 0;
	if (s1[i] == '\0')
		return ((char *)s2);
	while (s1[i] != '\0' && s2[u] != '\0' && u < len && i < len)
	{
		if (s1[i] == s2[u])
		{
			i++;
			u++;
		}
		else if (s1[i] != s2[u])
		{
			i = 0;
			u = o++;
		}
		if (s1[i] == '\0')
			return (&((char *)s2)[u - i]);
	}
	return (0);
}

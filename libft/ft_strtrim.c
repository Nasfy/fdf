/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:53:41 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/29 19:21:13 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	finish;
	unsigned int	buf;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_iswhitespace(s[start]) && s[start] != '\0')
		start++;
	finish = start;
	buf = start;
	while (s[finish++] != '\0')
		if (!ft_iswhitespace(s[finish - 1]) &&
				(ft_iswhitespace(s[finish]) || s[finish] == '\0'))
			buf = finish;
	return (ft_strsub(s, start, buf - start));
}

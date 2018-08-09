/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:02:08 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/28 15:23:10 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;
	unsigned int	q;

	i = start;
	q = 0;
	if (s == 0)
		return (0);
	new = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (s[i] != '\0' && len)
	{
		if (i >= start || len != 0)
		{
			new[q] = s[i];
			i++;
			q++;
			len--;
		}
		if (len == 0)
			break ;
	}
	new[q] = '\0';
	return (new);
}

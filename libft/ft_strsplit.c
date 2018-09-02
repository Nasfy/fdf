/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:50:31 by bcherkas          #+#    #+#             */
/*   Updated: 2018/08/31 19:32:20 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_delmass(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char		*ft_getword(char *s, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	word = ft_strsub(s, 0, len);
	return (word);
}

static size_t	ft_countwords(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			i++;
		s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	n;

	n = 0;
	if (s == NULL)
		return (0);
	arr = (char **)malloc(sizeof(char *) * (ft_countwords(s, c)) + 1);
	if (arr == NULL)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			if ((arr[n++] = ft_getword((char *)s, c)) == NULL)
			{
				ft_delmass(arr);
				return (NULL);
			}
		while (*s != c && *s)
			s++;
	}
	arr[n] = NULL;
	return (arr);
}

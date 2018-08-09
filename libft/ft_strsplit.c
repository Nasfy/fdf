/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:31:37 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/27 18:57:46 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count(char const *s, char c)
{
	size_t	n;
	size_t	nrows;

	n = 0;
	nrows = 0;
	while (s[n] != '\0')
	{
		if (s[n] != c && (s[n + 1] == c || s[n + 1] == '\0'))
			nrows++;
		n++;
	}
	return (nrows);
}

static void		ft_mass(char **arr, char const *s, char c)
{
	size_t			i;
	size_t			ncolumns;
	unsigned int	start;
	char			*ci;

	i = 0;
	ci = *arr;
	while (s[i] != '\0')
	{
		ncolumns = 0;
		while (s[i] == c)
			i++;
		start = i;
		while (s[i + ncolumns] != c && s[i + ncolumns] != '\0')
			ncolumns++;
		i += ncolumns;
		*arr = ft_strsub(s, start, ncolumns);
		if (*arr == NULL)
		{
			while (*(arr--) != ci)
				free(*arr);
			free(arr);
		}
		arr++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**arr;
	size_t	count;

	if (s == 0)
		return (0);
	count = ft_count(s, c);
	i = 0;
	arr = (char **)ft_memalloc(sizeof(char *) * (count + 1));
	if (arr == NULL)
		return (0);
	ft_mass(arr, s, c);
	arr[count] = 0;
	return (arr);
}

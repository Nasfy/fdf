/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:06:45 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/20 17:10:13 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t i;
	size_t n;
	size_t r;

	i = ft_strlen(dst);
	n = 0;
	r = i;
	if (i > dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[n] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[n];
		i++;
		n++;
	}
	dst[i] = '\0';
	return (r + ft_strlen(src));
}

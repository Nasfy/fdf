/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:59:02 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/08 18:10:54 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*(((unsigned char *)dest) + i) = *(((unsigned char *)src) + i);
		if (*(((unsigned char *)src) + i) == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}

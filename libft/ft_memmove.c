/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:35:04 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/20 17:15:09 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)dest) > ((unsigned char *)src))
			*(((unsigned char *)dest) + n - i - 1) =
				*(((unsigned char *)src) + n - i - 1);
		else
			*(((unsigned char *)dest) + i) = *(((unsigned char *)src) + i);
		i++;
	}
	return (dest);
}

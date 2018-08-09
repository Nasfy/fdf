/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:18:06 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/07 16:54:28 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)arr1)[i] == ((unsigned char *)arr2)[i])
			i++;
		else
			return (((unsigned char *)arr1)[i] - ((unsigned char *)arr2)[i]);
	}
	return (0);
}

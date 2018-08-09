/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:10:02 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/27 18:58:45 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*buf;

	buf = NULL;
	buf = (char*)malloc(sizeof(char) * size);
	if (buf == 0)
		return (0);
	ft_bzero(buf, size);
	return (buf);
}

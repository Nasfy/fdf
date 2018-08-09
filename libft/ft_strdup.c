/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:31:47 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/08 18:50:59 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*buf;
	size_t	i;

	i = ft_strlen(str);
	buf = (char*)malloc(sizeof(char) * (i + 1));
	if (buf == NULL)
		return (0);
	return (ft_strcpy(buf, str));
}

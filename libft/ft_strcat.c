/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:16:46 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/04 18:33:15 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strcat(char *dest, const char *app)
{
	size_t	u;
	size_t	len;

	u = 0;
	len = ft_strlen(dest);
	while (app[u] != '\0')
	{
		dest[len] = app[u];
		len++;
		u++;
	}
	dest[len] = '\0';
	return (dest);
}

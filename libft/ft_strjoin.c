/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:13:49 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/26 13:55:40 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*f;

	if (s1 == 0 || s2 == 0)
		return (0);
	len = (ft_strlen(s1) + ft_strlen(s2));
	f = (char *)malloc(sizeof(char) * (len + 1));
	if (f == NULL)
		return (NULL);
	ft_strcpy(f, s1);
	ft_strcat(f, s2);
	return (f);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 21:04:35 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/27 18:39:18 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strcmp(const char *str1, const char *str2)
{
	size_t			i;
	unsigned char	*q;
	unsigned char	*w;

	i = 0;
	q = (unsigned char*)str1;
	w = (unsigned char*)str2;
	while ((q[i] != '\0' && w[i]) != '\0' && q[i] == w[i])
	{
		i++;
	}
	return (q[i] - w[i]);
}

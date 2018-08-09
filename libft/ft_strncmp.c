/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:14:46 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/27 18:00:07 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*q;
	unsigned char	*w;

	q = (unsigned char*)str1;
	w = (unsigned char*)str2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && q[i] != '\0' && w[i] != '\0' && q[i] == w[i])
		i++;
	return (q[i] - w[i]);
}

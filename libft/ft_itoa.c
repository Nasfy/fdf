/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:05:31 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/27 18:59:26 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_sum(int n)
{
	int		rez;

	rez = (n < 0) ? 2 : 1;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		rez++;
	}
	return (rez);
}

char		*ft_itoa(int n)
{
	char		*rez;
	int			i;
	long long	c;

	i = ft_sum(n);
	c = n;
	rez = (char *)malloc(sizeof(char) * (i + 1));
	if (rez == 0)
		return (0);
	if (c < 0)
	{
		c = -c;
		rez[0] = '-';
	}
	rez[i] = '\0';
	if (c == 0)
		rez[--i] = '0';
	while (c > 0)
	{
		rez[--i] = (c % 10) + '0';
		c /= 10;
	}
	return (rez);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:34:10 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/28 15:18:27 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long int	rez;
	int					i;
	int					n;

	rez = 0;
	i = 0;
	n = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		n *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		rez = 10 * rez + (str[i] - '0');
		i++;
	}
	if (rez >= 9223372036854775807 && n == 1)
		return (-1);
	else if (rez > 9223372036854775807 && n == -1)
		return (0);
	else
		return (rez * n);
}

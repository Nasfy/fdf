/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_cont.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:37:47 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/29 13:03:33 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_del_cont(void *content, size_t content_size)
{
	if (content == NULL)
		return ;
	free(content);
	content = NULL;
	content_size = 0;
}

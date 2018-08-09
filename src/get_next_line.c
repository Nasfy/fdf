/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 20:04:07 by abiriuk           #+#    #+#             */
/*   Updated: 2018/03/09 18:42:26 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

int		free_list(t_list **start, t_list *list, char **line)
{
	t_list	*tmp;

	tmp = *start;
	if (tmp == list)
		*start = (*start)->next;
	while (tmp != list && tmp->next != list && tmp->next)
		tmp = tmp->next;
	tmp->next = list->next;
	ft_lstdelone(&list, ft_del_cont);
	if (*line)
		free(*line);
	*line = NULL;
	return (0);
}

char	*ft_strndup(const char *str, int size)
{
	char	*buffer;
	size_t	num;

	num = 0;
	buffer = (char *)malloc(sizeof(char) * (size_t)(size + 1));
	if (buffer == NULL)
		return (0);
	while (str[num] && num < (size_t)size)
	{
		buffer[num] = str[num];
		num++;
	}
	buffer[num] = '\0';
	return (buffer);
}

char	*content_join(t_list **list, char *buf, int rd)
{
	char	*tmp;
	size_t	len;

	if ((char *)(*list)->content == 0 || buf == 0)
		return (0);
	len = (ft_strlen((char *)(*list)->content) + (size_t)rd);
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	ft_strcpy(tmp, (char *)(*list)->content);
	ft_strncat(tmp, buf, (size_t)rd);
	free((*list)->content);
	return (tmp);
}

t_list	*ft_right_fd(const int fd, t_list **list)
{
	t_list	*temp;

	temp = *list;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", fd);
	temp = ft_lstadd_rev(list, temp);
	return (temp);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				rd;
	static t_list	*lst;
	t_list			*list;
	char			*temp;

	if (line)
		*line = NULL;
	if (fd < 0 || fd > 4096 || read(fd, buf, 0) < 0 || line == NULL)
		return (-1);
	list = ft_right_fd(fd, &lst);
	while (!ft_strchr(list->content, '\n') && (rd = read(fd, buf, BUFF_SIZE)))
		list->content = content_join(&list, buf, rd);
	if (*((char *)list->content) == 0)
		return (free_list(&lst, list, line));
	rd = 0;
	while (((char *)list->content)[rd] != '\n' && ((char *)list->content)[rd])
		rd++;
	*line = ft_strndup(list->content, rd);
	if (((char *)list->content)[rd] == '\n')
		rd++;
	temp = ft_strdup(&((char *)list->content)[rd]);
	free(list->content);
	list->content = temp;
	return (1);
}

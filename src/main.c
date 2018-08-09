/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:16:28 by abiriuk           #+#    #+#             */
/*   Updated: 2018/08/09 19:03:24 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "fdf.h"
#include "mlx.h"

void		error_msg(char *str)
{
	write(2, "ERROR: ", 7);
	write(2, "\x1b[31m", 6);
	write(2, str, ft_strlen(str));
	write(2, "\x1b[0m", 5);
	write(2, "\n", 1);
	exit(0);
}

void		check_symb(char elem)
{
	if (elem < 32 || (elem > 32 && elem < 44) || (elem > 44 && elem < 48) ||
			(elem > 57 && elem < 65) || (elem > 90 && elem < 97)
			|| elem > 122)
		error_msg("Wrong map");
}

char		*read_line(int fd)
{
	static char	buffer[10000];
	int			i;
	int			ret;

	i = 0;
	if ((ret = read(fd, &buffer[i++], 1)) == -1)
		error_msg("Is a directory");
	if (ret == 0)
		return (NULL);
	while (read(fd, &buffer[i], 1))
	{
		if (buffer[i] == '\n')
			break ;
		check_symb(buffer[i]);
		i++;
	}
	buffer[i] = 0;
	return (buffer);
}

t_global	*make_list(int fd)
{
	t_global	*tmp;
	t_global	*head;
	t_global	*cursor;
	char		*str;
	int			i;

	head = NULL;
	i = 0;
	while ((str = read_line(fd)))
	{
		tmp = new_global_node(check(ft_strsplit(str, ' '), i++));
		if (head == NULL)
		{
			head = tmp;
			cursor = head;
		}
		else
		{
			ft_link(cursor, tmp);
			cursor = tmp;
		}
	}
	if (i == 0)
		error_msg("File is empty");
	return (head);
}

int			main(int ac, char **av)
{
	int			fd;
	int			i;
	t_all		all;

	i = 0;
	if (ac != 2)
		return (0);
	all.move.y = 0;
	all.move.x = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == 0)
	{
		error_msg("No such file");
	}
	else if (fd == -1)
	{
		error_msg("Permission denied");
	}
	all.head = make_list(fd);
//	print_list(&all);
	cage(&all);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:30:31 by mbelalou          #+#    #+#             */
/*   Updated: 2017/12/24 19:39:47 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list_fd	*new_list_fd(int fd)
{
	t_list_fd *temp_result;

	temp_result = malloc(sizeof(temp_result));
	temp_result->fd = fd;
	temp_result->buf = ft_strnew(BUFF_SIZE);
	temp_result->next = NULL;
	return (temp_result);
}

//tester cette fonction .....
t_list_fd	*get_buf_fd(int fd, t_list_fd *list)
{
	if (!list)
	{
		list = new_list_fd(fd);
		return (list);
	}
	while ((list->fd != fd) && list->next)
		list = list->next;
	if (list->fd != fd && !list->next)
	{
		list->next = new_list_fd(fd);
		list = list->next;
	}
	return (list);
}


int			get_line(int fd, char **line)
{
	static t_list_fd	*list_fd;
	int					pt;
	char				*buf;
	char				*l;
	int					i;
	t_list_fd			*temp_fd;

	temp_fd = get_buf_fd(fd, list_fd);
	if (temp_fd->buf == NULL)
		while (temp_fd->buf[pt] != '\n')
		{
			read(temp_fd->fd, temp_fd->buf, BUFF_SIZE);
			while (temp_fd->buf[pt] && temp_fd->buf[pt] != '\n')
			{
				l[i++] = buf[pt];
				pt++;
			}
		}
/*	{
		pt = 0;
		ft_bzero(buf, BUFF_SIZE);
		read(fd, buf, BUFF_SIZE);
		*line = ft_strnew(BUFF_SIZE);
	}
	else
		ft_bzero(*line, BUFF_SIZE);
	i = 0;
	l = ft_strnew(BUFF_SIZE);
	*/
	pt++;
	ft_strlcat(*line, l, ft_strlen(l) + 1);
	free(l);
	return ((!buf[pt]) ? 0 : pt);
}

int				get_next_line(const int fd, char **line)
{
	if (fd < 0)
		return (-1);
	return (get_line(fd, line));
}

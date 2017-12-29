/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:30:31 by mbelalou          #+#    #+#             */
/*   Updated: 2017/12/25 21:27:22 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_line(int fd, char **line)
{
	static t_list_fd	*list_fd;
	int					pt;
	char				*buf;
	char				*l;
	int					i;
	t_list_fd			*temp_fd;

//	temp_fd = get_buf_fd(fd, list_fd);

	
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
/*
int				get_next_line(const int fd, char **line)
{
	if (fd < 0)
		return (-1);
	return (get_line(fd, line));
}*/


int		get_next_line(const int fd, char **line)
{
	static int i;
	char buf[BUFF_SIZE];
	int pt;

	ft_putstr("reading from file descriptor ");
	ft_putnbr(fd);
	ft_putstr("\n");

	ft_putstr("i begin ");
	ft_putnbr(i);
	//	int pt = 0;

//	if (buf == NULL)
	{
		read(fd, buf, BUFF_SIZE);
		ft_bzero(*line, BUFF_SIZE);
	}
	char *l = ft_strnew(BUFF_SIZE);
	//*line = ft_strnew(BUFF_SIZE); // a changer de taille

	while (buf[i] &&  buf[i] != '\n')
	{
		ft_putstr("\t");
		ft_putnbr(i);
		ft_putchar(buf[i]);
		l[i] = buf[i];
		i++;
	}

	// if i == BUFF_SIZE && buf [pt] != \n
//ft_putstr(l);

//	*line = ft_strnew(ft_strlen(l));
	ft_strlcat(*line, l, ft_strlen(l)+1);
	free (l);

	ft_putstr("\t\ti end ");
	ft_putnbr(i);
	return ((i < BUFF_SIZE) ? i++ : 0);
}

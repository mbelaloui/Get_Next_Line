/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:30:31 by mbelalou          #+#    #+#             */
/*   Updated: 2017/12/29 14:11:56 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_eol_char(char *buf)
{
	int i;

	i = 0;
	while (buf[i] || i < BUFF_SIZE)
	{
		if (buf[i] == '\n')
			 return 1;
		i++;
	}
	return 0;
}

int		get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE + 1];
	int i, len;
	char *rest;
	int trouver;

	ft_bzero(buf, BUFF_SIZE + 1);
	ft_putstr("line = <");
	len = 0;
	while (read(fd, buf, BUFF_SIZE) && !(trouver = is_eol_char(buf)))
	{
		i = 0;
//		ft_putstr(buf);
//		ft_putstr("\n--\n");
		while (buf[i] && buf[i] != '\n')
		{
			ft_putchar(buf[i++]);
			len++;
		}
	}
	if (trouver)
	{
		rest = ft_strnew(BUFF_SIZE);
		ft_putstr("\n trouver ");
		ft_putnbr(len);
		ft_putstr("\n****\n");
		ft_putstr(buf);
		ft_putstr("\n--\n");
		ft_putstr(">");
		ft_putstr("\n");
	}
	else
	{
		ft_putstr("pas trouver");
		ft_putstr("\n");
	}

/*	while (buf[i] && buf[i] != '\n')
	{
		ft_putchar(buf[i++]);
	}*/
	(void)line;
return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:30:31 by mbelalou          #+#    #+#             */
/*   Updated: 2017/12/29 17:46:16 by mbelalou         ###   ########.fr       */
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
	static	char *rest;
	int not_found_eol = 1;

	ft_bzero(buf, BUFF_SIZE + 1);
	ft_putstr("line = <");
	len = 0;
	i = 0;
	if(rest)
	{
//		ft_putstr("voila voila");
		i = 0;
		while (rest[i] && rest[i] != '\n')
		{
			ft_putchar(rest[i++]);
			len++;
		}
		ft_putstr(">");
		ft_putstr("\n rest : ");
		ft_putnbr(ft_strlen(rest) -i);
		if (i != 0)
		{
			if (rest[i] == '\n')
				i++;
			len = 0;
			while (rest[i])
			{
				rest[len++] = rest[i++];
			}
			rest[len] = '\0';
		}
		ft_putstr("\n****\n");
		rest = NULL;
	}
	else
	{
		while ((not_found_eol) && read(fd, buf, BUFF_SIZE))
		{
			i = 0;
			while (buf[i] && (not_found_eol = buf[i] != '\n'))
			{
				ft_putchar(buf[i++]);
				len++;
			}
		}
		rest = ft_strnew(BUFF_SIZE - (len % BUFF_SIZE));
		ft_putstr("\n rest : ");
		ft_putnbr(BUFF_SIZE - (len % BUFF_SIZE));
		if (buf[i] == '\n')
			i++;
		len = 0;
		while (buf[i])
		{
			rest[len++] = buf[i++];
		}
		rest[len] = '\0';
		ft_putstr("\n****\n");
		//	ft_putstr(buf);
	}
	ft_putstr("\n--\n");
	ft_putstr(">");
	ft_putstr(rest);
	ft_putstr("\n");

	/*	else
	{
		ft_putstr("pas trouver");
		ft_putstr("\n");
	}
*/
/*	while (buf[i] && buf[i] != '\n')
	{
		ft_putchar(buf[i++]);
	}*/
	(void)line;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:30:31 by mbelalou          #+#    #+#             */
/*   Updated: 2017/12/30 16:42:12 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is(char *buf)
{
	while (*buf)
	{
		if (*buf++ == '\n')
			return 1;
	}
	return 0;
}

int		get_next_line(const int fd, char **line)
{

	char buf[BUFF_SIZE + 1];
	int i,len = 0;
	*line = ft_strnew(1);
	char *rest;

	ft_bzero(buf, BUFF_SIZE + 1);
	ft_putstr("fichier = <");
	while (read(fd, buf, BUFF_SIZE) && !is(buf))
	{
		len +=ft_strlen(buf);
		*line = ft_strjoin(*line, buf);
		i = 0;
		while (buf[i])//pas de EOL caractere a copier dans ligne sans risque
		{
			ft_putchar(buf[i++]);
//			len++;
		}
//		ft_bzero(buf, BUFF_SIZE);
/*		ft_putstr(" \tline  lu <");
		ft_putstr(*line);
		ft_putstr(">\n");
*/
	}
	rest = ft_strnew(ft_strlen(buf));
	
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		rest[i] = buf[i];
		ft_putchar(buf[i++]);// pas de risaue ici aussi a concaterner sans problemes
		len++;
	}
	*line = ft_strjoin(*line, rest);

	ft_putstr("> \t len = ");
	ft_putnbr(len);
	ft_putstr("\n");

	rest = ft_strcut(buf, i + 1, ft_strlen(buf));

	i++;
	len = 0;
	ft_putstr("le rest de la ligne lu <");
	ft_putstr(rest);
/*	while (buf[i]) // le reste de la ligne lu
	{
		ft_putchar(buf[i++]);// pas de risaue ici aussi a concaterner sans problemes
		len++;
	}
*/	ft_putstr("> \t len = ");
	ft_putnbr(len);
	ft_putstr("\n");
/*
	ft_putstr("line  lu <");
	ft_putstr(*line);
	ft_putstr(">\n");



	*line = ft_strjoin(*line, buf);




*/
//	(void)line;
	return (0);
}














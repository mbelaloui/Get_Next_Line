/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:30:31 by mbelalou          #+#    #+#             */
/*   Updated: 2017/12/22 05:45:54 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static int i;
	char buf[4096];
	int pt = 0;

	ft_bzero(buf, 4096);
	read(fd, buf, 4096);
/*
	char *l = ft_strnew(4096);

	while (buf[pt] != '\n')
	{
		l[pt] = buf[pt];
		pt++;
	}



//	ft_putstr(l);

	ft_strlcat(*line, l, ft_strlen(l));
*/
	return (i++);
}

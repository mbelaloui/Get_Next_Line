/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:30:31 by mbelalou          #+#    #+#             */
/*   Updated: 2017/12/30 20:19:54 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		is_eof_char(char *buf)
{
	while (*buf)
	{
		if (*buf++ == '\n')
			return (1);
	}
	return (0);
}

static	int		read_file_fd(int fd, char **line, char **rest)// realoc
{
	char			buf[BUFF_SIZE + 1];
	int				i;
	int				ret;
	char				*temp;

	ft_bzero(buf, BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)) && !is_eof_char(buf))
	{
		temp = *line;
		*line = ft_strjoin(*line, buf);
		ft_strdel(&temp);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	ft_strdel(rest);
	*rest = ft_strnew(BUFF_SIZE);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		(*rest)[i] = buf[i];
		i++;
	}
	rest[0][i] = '\0';
	temp = *line;
	*line = ft_strjoin(*line, *rest);
	ft_strdel(&temp);
	ft_strdel(rest);
	*rest = ft_strcut(buf, i + 1, ft_strlen(buf));
	return (ret);
}

static	char	*read_file(char **line, char **src)
{
	int		i;
	char	*rest;
	char	*temp;

	rest = ft_strnew(ft_strlen(*src));
	i = 0;
	while ((src[0][i]) && ((src[0][i]) != '\n'))
	{
		rest[i] = src[0][i];
		i++;
	}
	rest[i] = '\0';
	temp = *line;
	*line = ft_strjoin(*line, rest);
	ft_strdel(&temp);
	ft_strdel(&rest);
	rest = ft_strcut(*src, i + 1, ft_strlen(*src));	
	ft_strdel(src);
	return (rest);
}

int				get_next_line(const int fd, char **line)// free (rest);
{
	static	char	*rest;
	int result;
	char		*temp;

	result = 1;
	if (fd <= 0 || !(*line = ft_strnew(0)))
		return (0);
	if (!rest || ft_isempty(rest))
		result = read_file_fd(fd, line, &rest);
	else
	{
		if (is_eof_char(rest))
		{
			rest = read_file(line, &rest);
		}
		else
		{
			temp = *line;
			*line = ft_strjoin(*line, rest);
			ft_strdel(&temp);
			result = read_file_fd(fd, line, &rest);
		}
	}
	if (!result)
	{
		ft_strdel(line);
		*line = ft_strnew(0);
		ft_strdel(&rest);
	}
	return (result);
}













































































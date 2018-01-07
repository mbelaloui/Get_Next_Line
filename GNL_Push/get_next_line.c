/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:30:31 by mbelalou          #+#    #+#             */
/*   Updated: 2018/01/07 12:13:21 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		read_file_fd(int fd, char **line, char **rest)
{
	char	buf[BUFF_SIZE + 1];
	int		i;
	int		ret;
	char	*temp;

	ft_bzero(buf, BUFF_SIZE + 1);
	while (((ret = read(fd, buf, BUFF_SIZE)) > 0) && !ft_is_c_in_str('\n', buf))
	{
		temp = *line;
		*line = ft_strjoin(*line, buf);
		ft_strdel(&temp);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	ft_strdel(rest);
	*rest = ft_strnew(BUFF_SIZE);
	i = -1;
	while (buf[++i] && buf[i] != '\n')
		(*rest)[i] = buf[i];
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

int				get_next_line(const int fd, char **line)
{
	static	char	*rest;
	int				result;
	char			*temp;

	result = 1;
	if (fd <= 0 || (line == NULL) || !(*line = ft_strnew(0)))
		return (-1);
	if (!rest || ft_isempty(rest))
		result = read_file_fd(fd, line, &rest);
	else
	{
		if (ft_is_c_in_str('\n', rest))
			rest = read_file(line, &rest);
		else
		{
			temp = *line;
			*line = ft_strjoin(*line, rest);
			ft_strdel(&temp);
			result = read_file_fd(fd, line, &rest);
		}
	}
	return ((result > 0) ? 1 : result);
}

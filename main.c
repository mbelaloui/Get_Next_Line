/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:33:13 by mbelalou          #+#    #+#             */
/*   Updated: 2017/12/30 19:39:54 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{

	int fd = 0, fd2 = 1;
	char *line = NULL;
	if (argc != 2)
		return (0);
	fd = ft_open_file(argv[1]);
	while ((fd2 != 0))
	{
		ft_putstr(" -> ");
		fd2 = get_next_line(fd, &line);
		ft_putstr(line);
		ft_putstr("\n");
		ft_strdel(&line);

	}
	close(fd);
	return (0);
}

































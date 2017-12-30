/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:33:13 by mbelalou          #+#    #+#             */
/*   Updated: 2017/12/30 15:54:47 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int fd = 0;
	char *line = NULL;
	fd = ft_open_file(argv[1]);
	int i = 0;
	while (i < 3)//(fd2 != 0))
	{
		ft_putstr("\n\t\t\t-------------------------------------------------\n");
		ft_putstr("\n i = ");
		ft_putnbr(++i);
		ft_putstr(" -> ");
		get_next_line(fd, &line);
		ft_putstr("\t : main ");
		ft_putstr(line);

	}
		ft_putstr("\n");
	close(fd);
	return (0);
}

































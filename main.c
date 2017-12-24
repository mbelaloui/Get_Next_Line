/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:33:13 by mbelalou          #+#    #+#             */
/*   Updated: 2017/12/24 18:20:11 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int fd = 0;//, fd2 = 0;
	char *line = NULL;
	fd = ft_open_file(argv[1]);
//	fd2 = ft_open_file(argv[2]);
	int i = 0;
	int pt = 1;

	while (pt > 0)
	{
//		ft_putstr("\t\t\t----------------------------------------------------------------------------------\n");
		ft_putstr("i = ");
		ft_putnbr(i++);
		ft_putstr("\t\t -> GNL : ");
		pt = get_next_line(fd, &line);
		ft_putstr("\t : main ");
		ft_putstr(line);
		ft_putstr("\n");
	}
		ft_putstr("\n");
	close(fd);
	return (0);
}

































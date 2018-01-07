/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:33:13 by mbelalou          #+#    #+#             */
/*   Updated: 2018/01/07 12:34:47 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL_Push/get_next_line.h"

int		main(int argc, char **argv)
{

	int fd = 1 , ret = -2;
	char *line = NULL;
	if (argc != 2)
		return (0);
	(void)argv;
	int i = -1;
	fd = ft_open_file(argv[1]);
	while (++i < 4)//(ret != 0)
	{
//		ft_putstr(" entrer du text -> <");
		ret = get_next_line(fd, &line);
//		ft_putstr(">\t\t votre text <");
	//	ft_putstr(line);
		ft_strdel(&line);
		
//		ft_putstr(">\n");

		ft_putstr("\t\t");
		ft_putnbr(ret);

	}
	close(fd);
	return (0);
}

































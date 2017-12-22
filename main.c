/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:33:13 by mbelalou          #+#    #+#             */
/*   Updated: 2017/12/22 05:45:02 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int fd = 0;
	char *line = ft_strnew(1);;

	fd = ft_open_file(argv[1]);



//	ft_putstr("fsdfsd");

	while (get_next_line(fd, &line) < 10)
		ft_putnbr(get_next_line(fd, &line));

	ft_putstr(line);

//	while (1);
	return (0);
}

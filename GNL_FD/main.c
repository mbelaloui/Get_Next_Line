/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:33:13 by mbelalou          #+#    #+#             */
/*   Updated: 2017/12/29 13:33:46 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
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

*/
int		main(int argc, char **argv)
{
	//t_list_fd *list = NULL;
	if (argc != 2)
		return (0);

	int pt = 1, i = 0;

	char *line = ft_strnew(BUFF_SIZE);//NULL;

	int fd_1 = open(argv[1], O_RDONLY);
/*	int fd_2 = open(argv[2], O_RDONLY);
	int fd_3 = open(argv[3], O_RDONLY);
	int fd_4 = open(argv[4], O_RDONLY);
	int fd_5 = open(argv[5], O_RDONLY);
*/
	if (!fd_1)// || !fd_2 || !fd_3 || !fd_4 || !fd_5)
		return (0);
	ft_putstr("\t*********************Begining*******************************\n");
/*
	ft_putstr("\t\tlist buf_fd\n");
	put_list_buf_fd(list);
*/
	ft_putstr("\t****************************************************\n");

	ft_putstr("\t\tFiles descriptors\n");
	ft_putstr("fd_1\t");
	ft_putnbr(fd_1);
	ft_putstr("\n");
/*
	ft_putstr("fd_2\t");
	ft_putnbr(fd_2);
	ft_putstr("\n");

	ft_putstr("fd_3\t");
	ft_putnbr(fd_3);
	ft_putstr("\n");

	ft_putstr("fd_4\t");
	ft_putnbr(fd_4);
	ft_putstr("\n");

	ft_putstr("fd_5\t");
	ft_putnbr(fd_5);
	ft_putstr("\n");
*/
	ft_putstr("\t****************************************************\n");
	ft_putstr("\t\t reading the file 1 <fd_ 1> \n");

	while (i < 6 && pt != 0)
	{
		ft_putstr("line = ");
		ft_putnbr(i++);
		ft_putstr("\t\t -> GNL : ");
		pt = get_next_line(fd_1, &line);
		ft_putstr("\n\t : main ");
		ft_putstr(line);
		ft_putstr("\n\n\n\n");

	}


	return (0);
}






























/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:30:31 by mbelalou          #+#    #+#             */
/*   Updated: 2017/12/30 15:54:17 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_eol_char(char *buf)
{
	int i;

	i = 0;
	while (buf[i] || i < BUFF_SIZE)
	{
//		ft_putchar(buf[i]);
		if (buf[i] == '\n')
			 return 1;
		i++;
	}
	return 0;
}

char	*get_cont_fd(int fd, char *buf)
{
	int i;
	int not_found_eol = 1;
	char *retour;

	while ((not_found_eol) && read(fd, buf, BUFF_SIZE))
	{
		i = 0;
		if ((not_found_eol = !is_eol_char(buf)))
		{
			retour = ft_strnew(ft_strlen(buf));
			while (buf[i])  // peut etre optimiser en appellant la fonction is_eol_char
			{
				retour[i] = buf[i];
				ft_putchar(buf[i++]);
			}
		}
	}
	ft_putstr(retour);
	//ft_strjoin(retour, buf);
	ft_putstr(">\t\t");
	return (retour);
}

int		get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE + 1];
	static	char *rest;

	ft_bzero(buf, BUFF_SIZE + 1);
	ft_putstr("line = <");

	if (rest) // il ya quelque chose dans rest
	{
		if (is_eol_char(rest))// FDL caractere
		{
			ft_putstr(" 1- la il faut copier depuis rest vers ligne\n");
			ft_putstr(" 2- decaler rest apres le caractere de FDL\n si le EOL et le dernier caractereer de rest rest = NULL");
			return (1);
		}
		else // pas de FDL
		{
			ft_putstr("la il faut lire et mettre ce qui'il ya dans buf dans rest.\n");
			ft_putstr("si cest EOF return 0\n");
			ft_putstr("si non continuer\n");

			rest = get_cont_fd(fd, buf); 
			ft_putstr(rest);
		}
	}
	else // il ya rien dans reste
	{
		ft_putstr("il ya rien dans reste il faut lire depui le buf et le mettre dans rest\n");
		ft_putstr(get_cont_fd(fd, buf)); // je suis sur qu'il ya EOF ou c'est EOF
		//ft_putstr(rest);
	}













	
	
	
	
	
	
	
	
	
	/*	len = 0;
	i = 0;
	if(rest)
	{
		if(!is_eol_char(rest))
		{
			while ((not_found_eol) && read(fd, buf, BUFF_SIZE))
			{
				rest = ft_strjoin(rest, buf);
				not_found_eol = !is_eol_char(rest);
			}
			ft_putstr("voila voila");
		}
		//ft_putstr(rest);
		i = 0;
		while (rest[i] && rest[i] != '\n')
		{
			ft_putchar(rest[i++]);
			len++;
		}
		ft_putstr(">");
		ft_putstr("\n rest : ");
		ft_putnbr(i);
		if (i != 0)
		{
			if (rest[i] == '\n')
				i++;
			len = 0;
			while (rest[i])
			{
				rest[len++] = rest[i++];
			}
			rest[len] = '\0';
		}
		ft_putstr("\n****\n");
	}
	else
	{
		rest = ft_strnew(BUFF_SIZE - (len % BUFF_SIZE));
		ft_putstr("\n rest : ");
		ft_putnbr(BUFF_SIZE - (len % BUFF_SIZE));
		if (buf[i] == '\n')
			i++;
		len = 0;
		while (buf[i])
		{
			rest[len++] = buf[i++];
		}
		rest[len] = '\0';
		ft_putstr("\n****\n");
	}
*/
	(void)line;
	(void)fd;
	return (0);
}

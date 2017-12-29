/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:31:04 by mbelalou          #+#    #+#             */
/*   Updated: 2017/12/25 16:35:53 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "Libft/libft.h"
# define BUFF_SIZE 110

typedef	struct			s_list_fd
{
	int					fd;
	char				*buf;
	struct s_list_fd	*next;
}						t_list_fd;

int						get_next_line(const int fd, char **line);

#endif

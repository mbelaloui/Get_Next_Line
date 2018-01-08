# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 21:48:22 by mbelalou          #+#    #+#              #
#    Updated: 2018/01/08 15:30:08 by mbelalou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	GNLRUN

FLAGES	=	-Wall -Wextra -Werror -fsanitize=address

SRCS	=	main.c\
			GNL_Push/libft/*.c\
			GNL_Push/get_next_line.c\


all			:	$(NAME)

$(NAME)		:	$(SRCS_P_1) $(SRCS) libmake
				@gcc $(FLAGES) $(SRCS) -o $(NAME) -L./GNL_Push/Libft/ -lft
				@echo fillit compilation complited successfully !

libmake:
				@make -C GNL_Push/libft/

clean		:	libclean

libclean	:
				@make -C GNL_Push/libft/ clean

fclean		:	clean libfclean
				@rm -f $(NAME)
				@echo cleaned the $(NAME) file
				@echo the fillit directory is totaly cleaned

libfclean	:
				@make -C GNL_Push/libft/ fclean

run			:	$(NAME)
	./$(NAME) testes/TP | cat -e
				@#testes/voila testes/test_1 testes/large_file.txt testes/gnl9_2.txt testes/gnl7_1.c

re			:	fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 16:07:30 by tbeauman          #+#    #+#              #
#    Updated: 2015/12/03 12:24:33 by rortega          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CFLAGS = -Wall -Wextra -Werror
FILES = ft_get_file.c solve.c check_tetriminos.c normhelper.c
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c $(CFLAGS) $(FILES)
	gcc $(CFLAGS) $(OBJS) -o $(NAME) -L. -lft

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

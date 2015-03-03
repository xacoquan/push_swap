#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/03 10:51:31 by xacoquan          #+#    #+#              #
#    Updated: 2015/03/03 11:02:46 by xacoquan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# -------------Compilateur------------------#
CC = cc
CFLAGS = -I./includes -O3
#--------------Name-------------------------#
NAME = Push_swap

#--------------Sources----------------------#
FILES = main.c          \
	pstools.c   \
	order.c

OBJECT = $(patsubst %.c,%.o,$(FILES))
BASEDIR = ./srcs
#-------------------------------------------#



#--------------Actions----------------------#

all:$(NAME)

$(NAME):
		$(CC) -c $(CFLAGS) $(addprefix $(BASEDIR)/, $(FILES))
	$(CC) -o $(NAME) $(OBJECT)

clean :
	/bin/rm -Rf $(OBJECT)

fclean: clean
	/bin/rm -Rf $(NAME)

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 12:49:23 by no-conne          #+#    #+#              #
#    Updated: 2019/07/17 11:15:54 by no-conne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvec.a

CC = gcc

IDIR = ./includes/

CFLAGS =  -Wall -Werror -Wextra -I$(IDIR)

SOURCES = *.c

OBJECTS = *.o

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c  $(SOURCES)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 10:12:50 by no-conne          #+#    #+#              #
#    Updated: 2019/07/17 11:18:07 by no-conne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

IDIR = ./includes/

LDIR = ./resources/minilibx_macos/

LIBDIR = ./libft/

libvecDIR = ./libvec_lib/

CFLAGS = -Wall -Werror -Wextra -I$(IDIR)

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SOURCES = main.c \

OBJECTS = *.o

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@make -C $(libvecDIR)
	@gcc $(CFLAGS) $(SOURCES) -L $(LIBDIR) -lft -L $(libvecDIR) -lvec -o $(NAME) -L$(LDIR) $(MLX_FLAGS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	@make -C $(LIBDIR)/ fclean
	@make -C $(libvecDIR)/ fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
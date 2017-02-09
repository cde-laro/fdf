# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/11 14:30:10 by cde-laro          #+#    #+#              #
#    Updated: 2017/02/09 20:57:49 by cde-laro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = fdf

SRC = srcs/main.c \
	  srcs/fdf_extract.c \
	  srcs/fdf_init.c \
	  srcs/fdf_draw.c \
	  srcs/fdf_matrice.c \
	  srcs/fdf_img_draw.c

LIB_NAME = libft.a

LIB = libft/libft.a

OBJ = main.o \
	  fdf_extract.o \
	  fdf_init.o \
	  fdf_draw.o \
	  fdf_matrice.o \
	  fdf_img_draw.o

INCLUDES = includes/

CFLAGS = -lmlx -framework OpenGL -framework AppKit -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(LIB_NAME)
	gcc -o $(NAME) $(SRC) $(LIB) $(CFLAGS) -I $(INCLUDES) 

$(LIB_NAME) :
	make -C libft all

clean :
	make -C libft clean
	rm -f $(OBJ)

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 15:35:23 by mtrisha           #+#    #+#              #
#    Updated: 2019/09/03 23:22:35 by mtrisha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCES = main.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -O3
debug: DEBUG = -g3

SRCDIR = ./
OBJDIR = ./

OBJECTS = $(SOURCES:.c=.o)
SRC = $(addprefix $(SRCDIR), $(SOURCES))
OBJ = $(addprefix $(OBJDIR), $(OBJECTS))

all: $(NAME)

$(NAME): ./libft.h $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

$(OBJDIR)%.o: ./libft.h $(SRCDIR)%.c
		$(CC) $(CFLAGS) $(DEBUG) -o $@ -c $^

compile: clean $(OBJ)

clean:
		rm -r -f $(OBJ)

fclean: clean
		rm -r -f $(NAME)

debug: all

re: fclean all

redebug: fclean debug
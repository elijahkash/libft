# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 15:35:23 by mtrisha           #+#    #+#              #
#    Updated: 2019/09/04 12:11:38 by mtrisha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
SOURCES = ft_putchar.c

DESTLIB = ./$(NAME).a
HEADER = ./$(NAME).h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -O3
debug: DEBUG = -g3

SRCDIR = ./sources/
OBJDIR = ./

OBJECTS = $(SOURCES:.c=.o)
SRC = $(addprefix $(SRCDIR), $(SOURCES))
OBJ = $(addprefix $(OBJDIR), $(OBJECTS))

all: $(NAME)

$(NAME): $(HEADER) $(OBJ)
		ar rc $(DESTLIB) $(OBJ)
		ranlib $(DESTLIB)

#######################################################
# DEL FIX FOR INCDIR
#######################################################
$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
		$(CC) $(CFLAGS) $(DEBUG) -o $@ -c $< -I ./

compile: clean $(OBJ)

clean:
		rm -r -f $(OBJ)

fclean: clean
		rm -r -f $(DESTLIB)

debug: all

re: fclean all

redebug: fclean debug
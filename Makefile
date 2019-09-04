# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 15:35:23 by mtrisha           #+#    #+#              #
#    Updated: 2019/09/04 11:21:22 by mtrisha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
SOURCES = main.c

DESTLIB = ./$(NAME).a
HEADER = ./$(NAME).h

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

$(NAME): $(HEADER) $(OBJ)
		ar rc $(DESTLIB) $(OBJ)
		ranlib $(DESTLIB)

$(OBJDIR)%.o: $(HEADER) $(SRCDIR)%.c
		$(CC) $(CFLAGS) $(DEBUG) -o $@ -c $^

compile: clean $(OBJ)

clean:
		rm -r -f $(OBJ)

fclean: clean
		rm -r -f $(NAME)

debug: all

re: fclean all

redebug: fclean debug
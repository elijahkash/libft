# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 15:35:23 by mtrisha           #+#    #+#              #
#    Updated: 2019/09/04 12:58:27 by mtrisha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
SOURCES = ft_putchar.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -O3
debug: DEBUG = -g3
MKDIR = mkdir -p

LIBDIR = ./
HEADERDIR = ./

SRCDIR = ./sources/
OBJDIR = ./objects/

LIB = $(LIBDIR)$(NAME).a
HEADER = $(HEADERDIR)$(NAME).h

OBJECTS = $(SOURCES:.c=.o)
SRC = $(addprefix $(SRCDIR), $(SOURCES))
OBJ = $(addprefix $(OBJDIR), $(OBJECTS))

all: $(NAME)

$(NAME): $(HEADER) $(OBJ) $(OBJDIR)
	ar rc $(LIB) $(OBJ)
	ranlib $(LIB)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER) $(OBJDIR)
	$(CC) $(CFLAGS) $(DEBUG) -o $@ -c $< -I $(HEADERDIR)

$(OBJDIR):
	$(MKDIR) $(OBJDIR)

compile: clean $(OBJ)

clean:
	rm -r -f $(OBJ)

fclean: clean
	rm -r -f $(LIB)

debug: all

re: fclean all

redebug: fclean debug
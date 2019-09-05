# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 15:35:23 by mtrisha           #+#    #+#              #
#    Updated: 2019/09/05 20:51:34 by mtrisha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
SOURCES = ft_putchar.c ft_putstr.c ft_putendl.c ft_putchar_fd.c ft_strlen.c\
ft_putstr_fd.c ft_putendl_fd.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_bzero.c ft_itoa.c\
ft_putnbr.c ft_putnbr_fd.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c\
ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c\
ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
ft_strsub.c ft_strtrim.c  ft_isws.c ft_strdup.c ft_strcpy.c ft_strncpy.c\
ft_strcat.c ft_strncat.c ft_strjoin.c ft_strlcat.c ft_strchr.c ft_strnequ.c\
ft_strrchr.c
# ft_strsplit.c

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

$(NAME): $(LIB)

$(LIB): $(HEADER) $(OBJ) $(OBJDIR)
	ar rc $(LIB) $(OBJ)
	ranlib $(LIB)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
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

test: testclean
	gcc -Wall -Wextra -Werror -g3 -o test test.c -L. -lft

testclean:
	rm -f test

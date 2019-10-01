# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 15:35:23 by mtrisha           #+#    #+#              #
#    Updated: 2019/10/01 11:51:15 by mtrisha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf
SOURCES = ft_putchar.c ft_putstr.c ft_putendl.c ft_putchar_fd.c ft_strlen.c\
ft_putstr_fd.c ft_putendl_fd.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_bzero.c ft_itoa.c\
ft_putnbr.c ft_putnbr_fd.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c\
ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c\
ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
ft_strsub.c ft_strtrim.c  ft_isws.c ft_strdup.c ft_strcpy.c ft_strncpy.c\
ft_strcat.c ft_strncat.c ft_strjoin.c ft_strlcat.c ft_strchr.c ft_strnequ.c\
ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_cwords.c\
ft_ccwords.c ft_findlwordlc.c ft_strsplit.c ft_atoi.c\
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
ft_free.c ft_lstfind.c ft_lstdelnode.c ft_remalloc.c ft_get_next_line.c\
ft_del_arr.c ft_pow.c ft_strset.c ft_zerostr.c ft_skip_digits.c\
ft_getnbr_base.c ft_outbuff.c \
ft_printf.c printf_src/handle_spec.c printf_src/read_spec.c \
printf_src/print_output.c printf_src/get_item_by_size.c \
printf_src/spectostr_percent.c printf_src/spectostr_string.c \
printf_src/spectostr_char.c printf_src/spectostr_ptr.c \
printf_src/spectostr_sdec.c printf_src/spectostr_oct.c \
printf_src/spectostr_lowhex.c printf_src/spectostr_bighex.c \
printf_src/spectostr_udec.c printf_src/spectostr_bin.c \
printf_src/change_fd.c printf_src/spectostr_float.c \
printf_src/extend_dollar.c printf_src/handle_stars.c \
printf_src/read_spec_funcs.c \
printf_src/bn_fix.c printf_src/bn_fstr.c printf_src/bn_init.c \
printf_src/bn_opers.c printf_src/bn_outp.c printf_src/bn_round.c \
printf_src/dbl_input.c printf_src/double.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -O3
debug: DEBUG = -g3
MKDIR = mkdir -p

LIBDIR = ./
SRCDIR = ./sources/
OBJDIR = ./objects/
INCDIR = ./includes/
DEBDIR = ./debug/

LIB = $(LIBDIR)$(NAME).a

OBJECTS1 = $(SOURCES:.c=.o)
OBJECTS = $(notdir $(OBJECTS1))
SRC = $(addprefix $(SRCDIR), $(SOURCES))
OBJ = $(addprefix $(OBJDIR), $(OBJECTS))

all: $(NAME)

$(NAME): depend $(LIB)

depend: $(OBJDIR).depend

$(OBJDIR).depend: $(SRC)
	$(CC) $(CFLAGS) -MM $(SRC) -I $(INCDIR) > $(OBJDIR).depend
	sed -i.bak  '/.o/s/^/objects\//g' $(OBJDIR).depend
	sed -i.bak  '/.o/s/objects\/  //g' $(OBJDIR).depend
	rm -rf $(OBJDIR).depend.bak

-include $(OBJDIR).depend

$(LIB): $(OBJDIR) $(OBJ)
	ar rc $(LIB) $(OBJ)
	ranlib $(LIB)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(DEBUG) -o $@ -c $< -I $(INCDIR)

$(OBJDIR)%.o: $(SRCDIR)printf_src/%.c
	$(CC) $(CFLAGS) $(DEBUG) -o $@ -c $< -I $(INCDIR)

clean: testclean
	rm -r -f $(OBJ)
	rm -rf $(OBJDIR).depend
	rm -rf $(OBJDIR).depend.bak

fclean: clean
	rm -r -f $(LIB)

debug: all

re: fclean
	$(MAKE)

redebug: fclean
	$(MAKE) debug

test: testclean
	$(CC) $(CFLAGS) -g3 -o $(DEBDIR)test $(DEBDIR)test.c -L $(LIBDIR) -lftprintf -I $(INCDIR)

testclean:
	rm -rf $(DEBDIR)*.dSYM/
	rm -f $(DEBDIR)test

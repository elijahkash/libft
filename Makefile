# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/12 21:57:42 by mtrisha           #+#    #+#              #
#    Updated: 2019/12/12 22:29:33 by mtrisha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

LIB = libft.a
CMAKEDIR = ./tmp/
CMAKEFILE = $(CMAKEDIR)Makefile
INCDIR = ./includes/
DEBDIR = ./debug/

all: $(NAME)

$(NAME): callcmake

callcmake: $(CMAKEDIR) $(CMAKEFILE)
	$(MAKE) -C $(CMAKEDIR)

$(CMAKEDIR):
	mkdir -p $(CMAKEDIR)

$(CMAKEFILE):
	cd $(CMAKEDIR); cmake ../

clean:
	rm -r -f $(CMAKEDIR)

fclean: clean
	rm -r -f $(LIB)

re: fclean
	$(MAKE)

# debug: all

# redebug: fclean
# 	$(MAKE) debug

# test: testclean
# 	gcc -Wall -Wextra -g3 -o $(DEBDIR)test $(DEBDIR)test.c -L ./ -lft \
# 	-I $(INCDIR)

# testclean:
# 	rm -rf $(DEBDIR)*.dSYM/
# 	rm -f $(DEBDIR)test

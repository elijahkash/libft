# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/12 21:57:42 by mtrisha           #+#    #+#              #
#    Updated: 2019/12/27 17:45:43 by mtrisha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

LIB = ./libft.a
DEBUGLIB = ./libftdebug.a
TEST = ./test/test
CMAKEDIR = ./tmp/

all: $(NAME)

$(NAME): callcmake

callcmake: $(CMAKEDIR) $(CMAKEDIR)Makefile
	$(MAKE) -C $(CMAKEDIR) $(MAKECMDGOALS)

$(CMAKEDIR):
	mkdir -p $(CMAKEDIR)

cmake: $(CMAKEDIR)
	cd $(CMAKEDIR); cmake ../

$(CMAKEDIR)Makefile:
	cd $(CMAKEDIR); cmake ../

clean:
	rm -r -f $(CMAKEDIR)
	rm -r -f $(TEST)

fclean: clean
	rm -r -f $(LIB)
	rm -r -f $(DEBUGLIB)

re: fclean
	$(MAKE)

debug: $(CMAKEDIR) $(CMAKEDIR)Makefile
	$(MAKE) -C $(CMAKEDIR) libftdebug

test: all

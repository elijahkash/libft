# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/12 21:57:42 by mtrisha           #+#    #+#              #
#    Updated: 2020/01/16 14:01:02 by Kashnitskiy      ###   ########.fr        #
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
	rm -r -f $(DEBUGLIB)
	rm -r -f $(CMAKEDIR)
	rm -r -f $(TEST)

fclean: clean
	rm -r -f $(LIB)

re: fclean
	$(MAKE)

debug: $(CMAKEDIR) $(CMAKEDIR)Makefile
	$(MAKE) -C $(CMAKEDIR) libftdebug

test: all

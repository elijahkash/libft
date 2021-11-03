#* ************************************************************************** *#
#*                                                                            *#
#*   Copyright (C) 2021 Ilya Kashnitskiy.                                     *#
#*   Contact: elijahkash.code@gmail.com                                       *#
#*                                                                            *#
#*   This file is part of the LIBFT project                                   *#
#*   https://github.com/elijahkash/libft                                      *#
#*                                                                            *#
#*   MIT License Usage                                                        *#
#*   This file may be used under the terms of the MIT License.                *#
#*   Check LICENSE included in the packaging of this file.                    *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = libft

CC = clang
CFLAGS = -Wall -Wextra -Werror -g -O2
ARFLAGS = rcs

LIB = $(NAME).a

SRC_DIR = sources
INC_DIR = includes

INC_PARAMS = $(INC_DIR:%=-I%)
CFLAGS += $(INC_PARAMS)

LIB_SRC = \
	$(SRC_DIR)/ft_deq/ft_deq_utils.c \
	$(SRC_DIR)/ft_deq/ft_deq_access.c \
	$(SRC_DIR)/ft_deq/ft_deq_pushpop.c \
	$(SRC_DIR)/ft_deq/ft_deq_base.c \
	$(SRC_DIR)/ft_fast_input_gnl.c \
	$(SRC_DIR)/ft_tstr.c \
	$(SRC_DIR)/ft_outbuff/ft_outbuff_add.c \
	$(SRC_DIR)/ft_outbuff/ft_outbuff_dst.c \
	$(SRC_DIR)/ft_outbuff/ft_outbuff_base.c \
	$(SRC_DIR)/ft_list/ft_lstnew.c \
	$(SRC_DIR)/ft_list/ft_lstadd.c \
	$(SRC_DIR)/ft_list/ft_lstmap.c \
	$(SRC_DIR)/ft_list/ft_lstfind.c \
	$(SRC_DIR)/ft_list/ft_lstdel.c \
	$(SRC_DIR)/ft_list/ft_lstiter.c \
	$(SRC_DIR)/ft_list/ft_lstdelone.c \
	$(SRC_DIR)/ft_list/ft_lstdelnode.c \
	$(SRC_DIR)/ft_diff_utils/ft_strtrim.c \
	$(SRC_DIR)/ft_diff_utils/ft_putendl.c \
	$(SRC_DIR)/ft_diff_utils/ft_memrev.c \
	$(SRC_DIR)/ft_diff_utils/ft_strdel.c \
	$(SRC_DIR)/ft_diff_utils/ft_memalloc.c \
	$(SRC_DIR)/ft_diff_utils/ft_striter.c \
	$(SRC_DIR)/ft_diff_utils/ft_strset.c \
	$(SRC_DIR)/ft_diff_utils/ft_strclr.c \
	$(SRC_DIR)/ft_diff_utils/ft_putnbr_fd.c \
	$(SRC_DIR)/ft_diff_utils/ft_putstr.c \
	$(SRC_DIR)/ft_diff_utils/ft_sfree.c \
	$(SRC_DIR)/ft_diff_utils/ft_skip_ws.c \
	$(SRC_DIR)/ft_diff_utils/ft_putchar_fd.c \
	$(SRC_DIR)/ft_diff_utils/ft_putnbr.c \
	$(SRC_DIR)/ft_diff_utils/ft_cwords.c \
	$(SRC_DIR)/ft_diff_utils/ft_iarr.c \
	$(SRC_DIR)/ft_diff_utils/ft_strnequ.c \
	$(SRC_DIR)/ft_diff_utils/ft_strnew.c \
	$(SRC_DIR)/ft_diff_utils/ft_putstr_fd.c \
	$(SRC_DIR)/ft_diff_utils/ft_write_unprint.c \
	$(SRC_DIR)/ft_diff_utils/ft_check_base.c \
	$(SRC_DIR)/ft_diff_utils/ft_getnbr_base.c \
	$(SRC_DIR)/ft_diff_utils/ft_del_arr.c \
	$(SRC_DIR)/ft_diff_utils/ft_striteri.c \
	$(SRC_DIR)/ft_diff_utils/ft_skip_digits.c \
	$(SRC_DIR)/ft_diff_utils/ft_skip_atoi.c \
	$(SRC_DIR)/ft_diff_utils/ft_strsub.c \
	$(SRC_DIR)/ft_diff_utils/ft_itoa.c \
	$(SRC_DIR)/ft_diff_utils/ft_findlwordlc.c \
	$(SRC_DIR)/ft_diff_utils/ft_swap.c \
	$(SRC_DIR)/ft_diff_utils/ft_strequ.c \
	$(SRC_DIR)/ft_diff_utils/ft_print_memory.c \
	$(SRC_DIR)/ft_diff_utils/ft_putchar.c \
	$(SRC_DIR)/ft_diff_utils/ft_pow.c \
	$(SRC_DIR)/ft_diff_utils/ft_memdel.c \
	$(SRC_DIR)/ft_diff_utils/ft_isdigit_ws.c \
	$(SRC_DIR)/ft_diff_utils/ft_strsplit.c \
	$(SRC_DIR)/ft_diff_utils/ft_putendl_fd.c \
	$(SRC_DIR)/ft_diff_utils/ft_ccwords.c \
	$(SRC_DIR)/ft_diff_utils/ft_strdup.c \
	$(SRC_DIR)/ft_diff_utils/ft_strmapi.c \
	$(SRC_DIR)/ft_diff_utils/ft_strjoin.c \
	$(SRC_DIR)/ft_diff_utils/ft_zerostr.c \
	$(SRC_DIR)/ft_diff_utils/ft_strmap.c \
	$(SRC_DIR)/ft_diff_utils/ft_is_empty_str.c \
	$(SRC_DIR)/ft_libc/ft_atoi.c \
	$(SRC_DIR)/ft_libc/ft_strncpy.c \
	$(SRC_DIR)/ft_libc/ft_memmove.c \
	$(SRC_DIR)/ft_libc/ft_isalnum.c \
	$(SRC_DIR)/ft_libc/ft_isws.c \
	$(SRC_DIR)/ft_libc/ft_strcmp_l.c \
	$(SRC_DIR)/ft_libc/ft_memccpy.c \
	$(SRC_DIR)/ft_libc/ft_isalpha.c \
	$(SRC_DIR)/ft_libc/ft_isdigit.c \
	$(SRC_DIR)/ft_libc/ft_strrchr.c \
	$(SRC_DIR)/ft_libc/ft_strcmp.c \
	$(SRC_DIR)/ft_libc/ft_strnstr.c \
	$(SRC_DIR)/ft_libc/ft_strncat.c \
	$(SRC_DIR)/ft_libc/ft_toupper.c \
	$(SRC_DIR)/ft_libc/ft_memset.c \
	$(SRC_DIR)/ft_libc/ft_strcat.c \
	$(SRC_DIR)/ft_libc/ft_tolower.c \
	$(SRC_DIR)/ft_libc/ft_strncmp.c \
	$(SRC_DIR)/ft_libc/ft_strlen.c \
	$(SRC_DIR)/ft_libc/ft_strlcat.c \
	$(SRC_DIR)/ft_libc/ft_strchr.c \
	$(SRC_DIR)/ft_libc/ft_isprint.c \
	$(SRC_DIR)/ft_libc/ft_strstr.c \
	$(SRC_DIR)/ft_libc/ft_isascii.c \
	$(SRC_DIR)/ft_libc/ft_memcmp.c \
	$(SRC_DIR)/ft_libc/ft_bzero.c \
	$(SRC_DIR)/ft_libc/ft_memcpy.c \
	$(SRC_DIR)/ft_libc/ft_memchr.c \
	$(SRC_DIR)/ft_libc/ft_strcpy.c \
	$(SRC_DIR)/ft_get_next_line.c \
	$(SRC_DIR)/ft_eval.c \
	$(SRC_DIR)/ft_memman/ft_malloc.c \
	$(SRC_DIR)/ft_memman/ft_memory_manager.c \
	$(SRC_DIR)/ft_memman/ft_free.c \
	$(SRC_DIR)/ft_memman/ft_remalloc.c \
	$(SRC_DIR)/ft_memman/ft_no_mm.c \
	$(SRC_DIR)/ft_sort.c \
	$(SRC_DIR)/ft_list_on_arr/ft_alst_access.c \
	$(SRC_DIR)/ft_list_on_arr/ft_alst_addpop.c \
	$(SRC_DIR)/ft_list_on_arr/ft_alst_base.c \
	$(SRC_DIR)/ft_list_on_arr/ft_alst_utils.c \
	$(SRC_DIR)/ft_error.c \
	$(SRC_DIR)/ft_vect/ft_vector_base.c \
	$(SRC_DIR)/ft_vect/ft_vector_pop.c \
	$(SRC_DIR)/ft_vect/ft_vector_add.c \
	$(SRC_DIR)/ft_vect/ft_vector_access.c \
	$(SRC_DIR)/ft_vect/ft_vector_utils.c \
	$(SRC_DIR)/ft_vect/ft_vector_sorted.c \
	$(SRC_DIR)/ft_options.c \
	$(SRC_DIR)/ft_cmp.c

LIB_OBJS := $(LIB_SRC:.c=.o)
LIB_DEPS := $(LIB_OBJS:.o=.d)

.PHONY: all clean fclean re

$(NAME): all

all: $(LIB)

%.d: %.c
	$(CC) $(CFLAGS) -MM $^ -MF "$@" -MT $(@:.d=.o)

ifneq ($(MAKECMDGOALS), fclean)
ifneq ($(MAKECMDGOALS), clean)
ifneq ($(MAKECMDGOALS), re)
 -include $(LIB_DEPS)
endif
endif
endif

$(LIB): $(LIB_OBJS)
	$(AR) $(ARFLAGS) $(LIB) $?

clean:
	rm -rf $(LIB_OBJS)
	rm -rf $(LIB_DEPS)

fclean: clean
	rm -rf $(LIB)

re: fclean
	$(MAKE)

/* ************************************************************************** */
/*                                                                            */
/*   Copyright (C) 2021 Ilya Kashnitskiy.                                     */
/*   Contact: elijahkash.code@gmail.com                                       */
/*                                                                            */
/*   This file is part of the LIBFT project                                   */
/*   https://github.com/elijahkash/libft                                      */
/*                                                                            */
/*   MIT License Usage                                                        */
/*   This file may be used under the terms of the MIT License.                */
/*   Check LICENSE included in the packaging of this file.                    */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# define FD_STDIN 0
# define FD_STDOUT 1
# define FD_STDERR 2

/*
** For usability
*/
# define PTR_SIZE __SIZEOF_POINTER__

# ifdef __linux__
#  include <stdint.h>
# endif

# include "ft_libft_mod.h"
# include "ft_compiler.h"
# include "ft_libc.h"
# include "ft_memory_manager.h"
# include "ft_vector.h"
# include "ft_deq.h"
# include "ft_list_on_arr.h"
# include "ft_error.h"
# include "ft_sort.h"
# include "ft_outbuff.h"
# include "ft_outbuff_dst.h"
# include "ft_eval.h"
# include "ft_cmp.h"
# include "ft_tstr.h"
# include "ft_list.h"
# include "ft_options.h"
# include "ft_get_next_line.h"
# include "ft_fast_input_gnl.h"
# include "ft_diff_utils.h"

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:15:30 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/18 16:39:48 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define TRUE (1)

# define FD_STDIN 0
# define FD_STDOUT 1
# define FD_STDERR 2

/*
** For usability
*/
# define PTR_SIZE __SIZEOF_POINTER__

/*
** https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
** used for micro-optimization
*/
# define LIKELY(x)   __builtin_expect(!!(x), 1)
# define UNLIKELY(x) __builtin_expect(!!(x), 0)

# include <ft_libft_mod.h>
# include <ft_libc.h>
# include <ft_memory_manager.h>
# include <ft_vector.h>
# include <ft_deq.h>
# include <ft_list_on_arr.h>
# include <ft_error.h>
# include <ft_sort.h>
# include <ft_printf.h>
# include <ft_outbuff.h>
# include <ft_outbuff_dst.h>
# include <ft_eval.h>
# include <ft_cmp.h>
# include <ft_bit_macro.h>
# include <ft_tstr.h>
# include <ft_list.h>
# include <ft_options.h>
# include <ft_get_next_line.h>
# include <ft_fast_input_gnl.h>
# include <ft_diff_utils.h>

/*
** Outdated functionality!
** Present for backward compatibility only!
** USE 't_vector' instead!
*/
# include <ft_dyn_arr.h>

#endif

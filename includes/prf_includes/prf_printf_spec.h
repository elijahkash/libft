/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_printf_spec.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:56:44 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/21 19:33:36 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRF_PRINTF_SPEC_H
# define PRF_PRINTF_SPEC_H

# include <stdarg.h>

# define NUMBER_OF_SPECS 16
# define NUMBER_OF_SIZES 5

# define ALL_BITS	(0 - 1)
# define UNSIG_BITS	(1 | 2 | 16)

# define FLAGS		"0-+ '#"

/*
**	shoud be in same order(by id) as FLAGS
*/
# define FLAG_ZERO	1
# define FLAG_MINUS	2
# define FLAG_PLUS	4
# define FLAG_SPACE	8
# define FLAG_COMMA	16
# define FLAG_OCTT	32

# define SIZE_MAX_LEN 2

/*
**	shoud be in same order(by id) as sizes_map
*/
# define SIZE_LL	1
# define SIZE_HH	2
# define SIZE_L		4
# define SIZE_H		8
# define SIZE_UP_L	16

# define NOT_DETERM (1 << (sizeof(int) * 8 - 1))
# define READ_DATA	(NOT_DETERM + 1)

# define DEC_BASE "0123456789"
# define OCT_BASE "01234567"
# define BIN_BASE "01"
# define BIG_HEX_BASE "0123456789ABCDEF"
# define LOW_HEX_BASE "0123456789abcdef"

/*
** spec == 0: wrong spec; else spec == index in g_specs_def
** width < 0 && > READ_DATA: dollar mode
** same shit with precision
** arg > 0: dollar mode else arg < 0 (usual mode)
*/
typedef struct	s_specifications_def
{
	char	spec;
	int		flags;
	int		width;
	int		precision;
	int		sizes;
	int		arg;
}				t_specifications_def;

typedef char	*(*t_spectostr_func)(t_specifications_def spec, va_list argptr);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:56:44 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/25 15:14:42 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_SPEC_H
# define FT_PRINTF_SPEC_H

# include <stdarg.h>

# define NUMBER_OF_SPECS 12
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

# define READ_DATA	(-2)
# define NOT_DETERM (-1)

# define DEC_BASE "0123456789"
# define OCT_BASE "01234567"
# define BIN_BASE "01"
# define BIG_HEX_BASE "0123456789ABCDEF"
# define LOW_HEX_BASE "0123456789abcdef"

typedef struct	s_specifications_def
{
	char	spec;
	int		flags;
	int		width;
	int		precision;
	int		sizes;
}				t_specifications_def;

const char		*is_valid_spec(const char *format);
int				handle_spec(const char **format, va_list argptr);

typedef char	*(*t_spectostr_func)(t_specifications_def spec, va_list argptr);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:56:44 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/19 23:05:09 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_SPEC_H
# define FT_PRINTF_SPEC_H

# include <stdarg.h>
# include <string.h>

# define NUMBER_OF_SPECS 15

# define ALL_BITS	(0 - 1)
# define UNSIG_BITS	(1 & 2 & 16)

# define FLAG_ZERO	1
# define FLAG_MINUS	2
# define FLAG_PLUS	4
# define FLAG_SPACE	8
# define FLAG_COMMA	16

# define SIZE_L		1
# define SIZE_UP_L	2
# define SIZE_LL	3
# define SIZE_HH	8
# define SIZE_H		16

# define READ_DATA	(-1)

typedef struct	s_specifications_def
{
	const char	spec;
	const int	flags;
	const int	width;
	const int	precision;
	const int	sizes;
}				t_specifications_def;

const t_specifications_def specs_def[NUMBER_OF_SPECS] = {
	{'%', 0, 0, 0, 0},
	{'s', 2, 1, 1, 1},
	{'c', 2, 1, 0, 1},
	{'p', 2, 1, 0, 0},
	{'d', ALL_BITS,  1, 1, ALL_BITS},
	{'i', ALL_BITS,  1, 1, ALL_BITS},
	{'o', UNSIG_BITS,  1, 1, ALL_BITS},
	{'u', UNSIG_BITS,  1, 1, ALL_BITS},
	{'x', UNSIG_BITS, 1, 1, ALL_BITS},
	{'X', UNSIG_BITS, 1, 1, ALL_BITS},
	{'f', ALL_BITS, 1, 1, SIZE_UP_L},
	{'e', 1 & 2 & 4 & 8, 1, 1, SIZE_UP_L},
	{'g', ALL_BITS, 1, 1, SIZE_UP_L},
	{'b', 2, 1, 1, 0},
	{'r', 2, 1, 1, 0}};

static int	is_valid_spec(const char *format);
static int	handle_spec(const char **format, va_list argptr)

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:56:44 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/20 15:55:42 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_SPEC_H
# define FT_PRINTF_SPEC_H

# include <stdarg.h>
# include <string.h>

# define NUMBER_OF_SPECS 15
# define NUMBER_OF_SIZES 5

# define ALL_BITS	(0 - 1)
# define UNSIG_BITS	(1 & 2 & 16)

# define FLAGS		"0-+ '"
# define FLAG_ZERO	1
# define FLAG_MINUS	2
# define FLAG_PLUS	4
# define FLAG_SPACE	8
# define FLAG_COMMA	16

/*
**	place sizes in priority order (or by length)
*/
const char	*sizes_map[NUMBER_OF_SIZES] = {
	"ll", "hh", "l", "L", "h"};
# define SIZE_MAX_LEN 2

# define SIZE_L		4
# define SIZE_UP_L	8
# define SIZE_LL	1
# define SIZE_HH	2
# define SIZE_H		16

# define READ_DATA	(-1)

typedef struct	s_specifications_def
{
	char	spec;
	int		flags;
	int		width;
	int		precision;
	int		sizes;
}				t_specifications_def;

const t_specifications_def specs_def[NUMBER_OF_SPECS] = {
	{'%', 0, 0, 0, 0},
	{'s', 2, 1, 1, SIZE_L},
	{'c', 2, 1, 0, SIZE_L},
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

int			is_valid_spec(const char *format);
int			handle_spec(const char **format, va_list argptr);
const char	*read_spec(const char *format, t_specifications_def *spec);

const char	*skip_digits(const char *format);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:56:44 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/22 13:55:14 by mtrisha          ###   ########.fr       */
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

# define SIZE_MAX_LEN 2

/*
**	shoud be in same order(by id) as sizes_map
*/
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

const char		*is_valid_spec(const char *format);
int				handle_spec(const char **format, va_list argptr);

typedef char	*(*t_spectostr_func)(t_specifications_def spec, va_list argptr);

#endif

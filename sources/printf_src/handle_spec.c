/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:57:15 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/21 15:50:37 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_spec.h>

#include <libft.h>
#include <read_spec.h>
#include <print_funcs.h>

/*
**	place sizes in priority order (or by length)
*/
static const char					*g_sizes_map[NUMBER_OF_SIZES] = {
	"ll", "hh", "l", "L", "h"};

static const t_specifications_def	g_specs_def[NUMBER_OF_SPECS] = {
	{'%', ALL_BITS, 1, 1, ALL_BITS},
	{'s', 2, 1, 1, SIZE_L},
	{'c', 2, 1, 0, SIZE_L},
	{'p', 2, 1, 0, 0},
	{'d', ALL_BITS,  1, 1, ALL_BITS - SIZE_UP_L},
	{'i', ALL_BITS,  1, 1, ALL_BITS - SIZE_UP_L},
	{'o', FLAG_MINUS + FLAG_ZERO, 1, 1, ALL_BITS - SIZE_UP_L},
	{'u', UNSIG_BITS,  1, 1, ALL_BITS - SIZE_UP_L},
	{'x', FLAG_MINUS + FLAG_ZERO, 1, 1, ALL_BITS- SIZE_UP_L},
	{'X', FLAG_MINUS + FLAG_ZERO, 1, 1, ALL_BITS- SIZE_UP_L},
	{'f', ALL_BITS, 1, 1, SIZE_UP_L + SIZE_L},
	{'e', 1 & 2 & 4 & 8, 1, 1, SIZE_UP_L + SIZE_L},
	{'g', ALL_BITS, 1, 1, SIZE_UP_L + SIZE_L},
	{'b', 2, 1, 1, 0},
	{'r', 2, 1, 1, 0}};

static const print_func				g_arr_print_funcs[NUMBER_OF_SPECS] = {
	print_percent
};

int			check_spec(t_specifications_def spec)
{
	if (!spec.spec)
		return (-1);
	if (!(spec.flags & g_specs_def[spec.spec - 1].flags) && (spec.flags))
		return (-1);
	if (!(spec.sizes & g_specs_def[spec.spec - 1].sizes) && (spec.sizes))
		return (-1);
	if (spec.width && !g_specs_def[spec.spec - 1].width)
		return (-1);
	if (spec.precision && !g_specs_def[spec.spec - 1].precision)
		return (-1);
	if (spec.flags & FLAG_PLUS)
		spec.flags &= (~FLAG_SPACE);
//	if (spec.precision)
//		spec.flags &= (~FLAG_ZERO);
	return (0);
}

const char	*read_spec(const char *format, t_specifications_def *spec)
{
	while (read_flag(format, spec))
		format++;
	if (ft_isdigit(*format))
	{
		spec->width = ft_atoi(format);
		format = skip_digits(format);
	}
	if (*format == '.')
	{
		spec->precision = ft_atoi(++format);
		format = skip_digits(format);
	}
	format = read_size(format, spec, g_sizes_map);
	format = read_specification(format, spec, g_specs_def);
	return (format);
}

const char	*is_valid_spec(const char *format)
{
	t_specifications_def spec;

	if (*format++ != '%')
		return (0);
	ft_bzero(&spec, sizeof(t_specifications_def));
	if (!(format = read_spec(format, &spec)))
		return (0);
	if (check_spec(spec))
		return (0);
	return (format);
}

int		handle_spec(const char **format, va_list argptr)
{
	t_specifications_def	spec;

	if (*(*format)++ != '%')
		return (0);
	ft_bzero(&spec, sizeof(t_specifications_def));
	*format = read_spec(*format, &spec);
	return (g_arr_print_funcs[spec.spec - 1](spec, argptr));
}

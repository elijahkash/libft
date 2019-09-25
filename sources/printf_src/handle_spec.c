/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:57:15 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/25 13:35:10 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_spec.h>

#include <libft.h>
#include <read_spec.h>
#include <spectostr_funcs.h>
#include <print_output.h>

#include <stdlib.h>

/*
**	place sizes in priority order (or by length)
*/
static const char					*g_sizes_map[NUMBER_OF_SIZES] = {
	"ll", "hh", "l", "h", "L"};

static const t_specifications_def	g_specs_def[NUMBER_OF_SPECS] = {
	{'%', ALL_BITS, 1, 1, ALL_BITS},
	{'s', 2, 1, 1, 0},
	{'c', 2, 1, 0, 0},
	{'p', 2, 1, 0, 0},
	{'d', ALL_BITS, 1, 1, ALL_BITS - SIZE_UP_L},
	{'i', ALL_BITS, 1, 1, ALL_BITS - SIZE_UP_L},
	{'o', FLAG_MINUS + FLAG_ZERO, 1, 1, ALL_BITS - SIZE_UP_L},
	{'u', UNSIG_BITS, 1, 1, ALL_BITS - SIZE_UP_L},
	{'x', FLAG_MINUS + FLAG_ZERO, 1, 1, ALL_BITS - SIZE_UP_L},
	{'X', FLAG_MINUS + FLAG_ZERO, 1, 1, ALL_BITS - SIZE_UP_L},
	{'f', ALL_BITS, 1, 1, SIZE_UP_L + SIZE_L},
	{'e', 1 & 2 & 4 & 8, 1, 1, SIZE_UP_L + SIZE_L},
	{'g', ALL_BITS, 1, 1, SIZE_UP_L + SIZE_L},
	{'b', 2, 1, 1, 0},
	{'r', 2, 1, 1, 0}};

static const t_spectostr_func		g_arr_spectostr_funcs[NUMBER_OF_SPECS] = {
	spectostr_percent,
	spectostr_string,
	spectostr_char,
	spectostr_ptr,
	spectostr_sdec,
	spectostr_sdec,
	spectostr_oct,
	spectostr_udec,
	spectostr_lowhex,
	spectostr_bighex
};

static int							check_spec(t_specifications_def spec)
{
	if (!spec.spec)
		return (-1);
	if (!(spec.flags & g_specs_def[spec.spec - 1].flags) && (spec.flags))
		return (-1);
	if (!(spec.sizes & g_specs_def[spec.spec - 1].sizes) && (spec.sizes))
		return (-1);
	if (spec.width != NOT_DETERM && !g_specs_def[spec.spec - 1].width)
		return (-1);
	if (spec.precision != NOT_DETERM && !g_specs_def[spec.spec - 1].precision)
		return (-1);
	return (0);
}

const char							*is_valid_spec(const char *format)
{
	t_specifications_def spec;

	if (*format++ != '%')
		return (0);
	ft_bzero(&spec, sizeof(t_specifications_def));
	if (!(format = read_spec(format, &spec, g_specs_def, g_sizes_map)))
		return (0);
	if (check_spec(spec))
		return (0);
	return (format);
}

static void							handle_stars(t_specifications_def *spec,
												va_list argptr)
{
	if (spec->width == READ_DATA)
	{
		spec->width = va_arg(argptr, int);
		if (spec->width < 0)
		{
			spec->width *= -1;
			spec->flags |= FLAG_MINUS;
		}
	}
	if (spec->precision == READ_DATA)
	{
		spec->precision = va_arg(argptr, int);
		if (spec->precision < 0)
			spec->precision = NOT_DETERM;
		if (spec->spec >= 6 && spec->spec <= 11 &&
			spec->precision != NOT_DETERM)
			spec->flags &= (~FLAG_ZERO);
	}
}

static int							print_spec(t_specifications_def spec,
												va_list argptr)
{
	int		result;
	char	*output;

	handle_stars(&spec, argptr);
	output = g_arr_spectostr_funcs[spec.spec - 1](spec, argptr);
	if (!output)
		return (-1);
	if (spec.flags & FLAG_COMMA)
		handle_comma_flag(&output);
	if (!output)
		return (-1);
	result = print_output(spec, &output);
	if (output)
		free(output);
	return (result);
}

int									handle_spec(const char **format,
												va_list argptr)
{
	t_specifications_def	spec;

	if (*(*format)++ != '%')
		return (0);
	ft_bzero(&spec, sizeof(t_specifications_def));
	*format = read_spec(*format, &spec, g_specs_def, g_sizes_map);
	prepare_spec(&spec);
	return (print_spec(spec, argptr));
}

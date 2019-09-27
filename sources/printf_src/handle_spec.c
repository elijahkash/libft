/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:57:15 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/27 23:30:00 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <handle_spec.h>

#include <ft_printf_spec.h>
#include <libft.h>
#include <read_spec.h>
#include <spectostr_funcs.h>
#include <print_output.h>
#include <handle_stars.h>

#include <stdlib.h>

/*
**	place sizes in priority order (or by length)
*/
static const char					*g_sizes_map[NUMBER_OF_SIZES] = {
	"ll", "hh", "l", "h", "L"};

/*
**	{'e', ALL_BITS - FLAG_COMMA, 1, 1, SIZE_UP_L + SIZE_L},
**	{'g', ALL_BITS, 1, 1, SIZE_UP_L + SIZE_L},
**	{'r', 2, 1, 1, 0}};
*/
static const t_specifications_def	g_specs_def[NUMBER_OF_SPECS] = {
	{'%', ALL_BITS, 1, 1, ALL_BITS, 0},
	{'s', 2, 1, 1, 0, 0},
	{'c', 2, 1, 0, 0, 0},
	{'p', 2, 1, 0, 0, 0},
	{'d', ALL_BITS, 1, 1, ALL_BITS - SIZE_UP_L, 0},
	{'i', ALL_BITS, 1, 1, ALL_BITS - SIZE_UP_L, 0},
	{'o', FLAG_MINUS + FLAG_ZERO + FLAG_OCTT, 1, 1, ALL_BITS - SIZE_UP_L, 0},
	{'u', UNSIG_BITS, 1, 1, ALL_BITS - SIZE_UP_L, 0},
	{'x', FLAG_MINUS + FLAG_ZERO + FLAG_OCTT, 1, 1, ALL_BITS - SIZE_UP_L, 0},
	{'X', FLAG_MINUS + FLAG_ZERO + FLAG_OCTT, 1, 1, ALL_BITS - SIZE_UP_L, 0},
	{'b', FLAG_MINUS + FLAG_ZERO + FLAG_OCTT, 1, 1, ALL_BITS - SIZE_UP_L, 0},
	{'f', ALL_BITS, 1, 1, SIZE_UP_L + SIZE_L, 0},
	{'w', 0, 0, 0, 0, 0}};

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
	spectostr_bighex,
	spectostr_bin,
	spectostr_float,
	change_fd
};

/*
** if dollar mode g_arg_mode > 0 else < 0
*/
static int							g_arg_mode = 0;

void								re_init_argmode(void)
{
	g_arg_mode = 0;
}

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
	if (!g_arg_mode)
		g_arg_mode = (spec.arg > 0) ? 1 : -1;
	if (spec.arg * g_arg_mode < 0
		|| (spec.width > READ_DATA && spec.width < 0 && g_arg_mode < 0)
		|| (spec.precision > READ_DATA && spec.precision < 0 && g_arg_mode < 0)
		|| (spec.precision == READ_DATA && g_arg_mode > 0)
		|| (spec.width == READ_DATA && g_arg_mode > 0))
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

static int							print_spec(t_specifications_def spec,
												va_list argptr)
{
	int		result;
	char	*output;

	handle_stars(&spec, argptr, g_arg_mode);
	if (spec.arg > 0)
		while ((spec.arg)-- > 1)
			va_arg(argptr, long long);
	output = g_arr_spectostr_funcs[spec.spec - 1](spec, argptr);
	//TODO: double special number handler
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
	va_list					tmp;

	if (*(*format)++ != '%')
		return (0);
	ft_bzero(&spec, sizeof(t_specifications_def));
	*format = read_spec(*format, &spec, g_specs_def, g_sizes_map);
	prepare_spec(&spec);
	(spec.arg > 0) ? va_copy(tmp, argptr) : 0;
	return (print_spec(spec, (spec.arg > 0) ? tmp : argptr));
}

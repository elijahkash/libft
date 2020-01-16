/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:57:15 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:58:08 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_handle_spec.h>

#include <prf_printf_spec.h>
#include <libft.h>
#include <prf_read_spec.h>
#include <prf_spectostr_funcs.h>
#include <prf_print_output.h>
#include <prf_handle_stars.h>
#include <prf_arg_mode.h>
#include <prf_extend_dollar.h>
#include <prf_handle_comma_flag.h>

/*
**	place sizes in priority order (or by length)
*/
static const char					*g_sizes_map[NUMBER_OF_SIZES] = {
	"ll", "hh", "l", "h", "L"};

/*
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
	{'w', 0, 0, 0, 0, 0},
	{'e', ALL_BITS, 1, 1, SIZE_UP_L + SIZE_L, 0},
	{'E', ALL_BITS, 1, 1, SIZE_UP_L + SIZE_L, 0},
	{'y', 0, 0, 0, 0, 0}};

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
	change_fd,
	spectostr_float,
	spectostr_float,
	change_outstr
};

static const char					*read_spec(const char *format,
												t_specifications_def *spec)
{
	if (is_dollar(format) && (spec->arg = ft_atoi(format)))
		format = skip_dollar(format);
	else
		spec->arg = -1;
	while (read_flag(format, spec))
		format++;
	format = read_width(format, spec);
	format = read_precision(format, spec);
	format = read_size(format, spec, g_sizes_map);
	format = read_specification(format, spec, g_specs_def);
	return (format);
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
	if (spec.precision != NOT_DETERM && spec.precision
									&& !g_specs_def[spec.spec - 1].precision)
		return (-1);
	if (!get_argmode())
		set_argmode((spec.arg > 0) ? 1 : -1);
	if (spec.arg * get_argmode() < 0
	|| (spec.width > READ_DATA && spec.width < 0 && get_argmode() < 0)
	|| (spec.precision > READ_DATA && spec.precision < 0 && get_argmode() < 0)
	|| (spec.precision == READ_DATA && get_argmode() > 0)
	|| (spec.width == READ_DATA && get_argmode() > 0))
		return (-1);
	return (0);
}

const char							*is_valid_spec(const char *format)
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

static int							print_spec(t_specifications_def spec,
												va_list argptr)
{
	int		result;
	char	*output;

	handle_stars(&spec, argptr, get_argmode());
	if (spec.arg > 0)
		while ((spec.arg)-- > 1)
			va_arg(argptr, long long);
	output = g_arr_spectostr_funcs[spec.spec - 1](spec, argptr);
	if (spec.spec == 12 && (ft_strstr(output, "inf")
							|| ft_strstr(output, "nan")))
		spec.flags &= ~FLAG_COMMA & ~FLAG_ZERO;
	if (spec.spec == 12 && ft_strstr(output, "nan"))
		spec.flags &= ~FLAG_SPACE & ~FLAG_PLUS;
	if (!output)
		return (-1);
	if (spec.flags & FLAG_COMMA)
		handle_comma_flag(output);
	if (!output)
		return (-1);
	result = print_output(spec, &output);
	if (output)
		ft_free(output);
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
	*format = read_spec(*format, &spec);
	prepare_spec(&spec);
	(spec.arg > 0) ? va_copy(tmp, argptr) : 0;
	return (print_spec(spec, (spec.arg > 0) ? tmp : argptr));
}

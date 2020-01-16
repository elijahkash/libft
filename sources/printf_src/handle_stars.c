/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 23:13:16 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:58:08 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_handle_stars.h>

static void	handle_width_star(t_specifications_def *spec, va_list argptr)
{
	if (spec->width >= READ_DATA && spec->width < 0)
	{
		if (spec->width != READ_DATA)
		{
			while ((spec->width)++ < -1)
				va_arg(argptr, long long);
			spec->width = va_arg(argptr, int);
		}
		else
			spec->width = va_arg(argptr, int);
		if (spec->width < 0)
		{
			spec->width *= -1;
			spec->flags |= FLAG_MINUS;
		}
	}
}

static void	handle_precision_star(t_specifications_def *spec, va_list argptr)
{
	if (spec->precision >= READ_DATA && spec->precision < 0)
	{
		if (spec->precision != READ_DATA)
		{
			while ((spec->precision)++ < -1)
				va_arg(argptr, long long);
			spec->precision = va_arg(argptr, int);
		}
		else
			spec->precision = va_arg(argptr, int);
		if (spec->precision < 0)
			spec->precision = NOT_DETERM;
		if (spec->spec >= 6 && spec->spec <= 11 &&
			spec->precision != NOT_DETERM)
			spec->flags &= (~FLAG_ZERO);
	}
}

void		handle_stars(t_specifications_def *spec, va_list argptr,
													int g_arg_mode)
{
	va_list	tmp;

	va_copy(tmp, argptr);
	handle_width_star(spec, (g_arg_mode > 0) ? tmp : argptr);
	va_copy(tmp, argptr);
	handle_precision_star(spec, (g_arg_mode > 0) ? tmp : argptr);
}

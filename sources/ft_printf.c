/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:50:58 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/19 14:15:23 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include <libft.h>
#include <prf_handle_spec.h>
#include <prf_global_bak.h>
#include <prf_out_fd.h>

static int	is_valid_format(const char *format)
{
	while (*format)
		if (*format != '%')
			format++;
		else if (!(format = is_valid_spec(format)))
			return (0);
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list			argptr;
	int				result;
	int				ret;
	t_global_bak	bak;

	bak = global_init();
	if (!(is_valid_format(format) + (result = 0) * 0))
		return (-1 + global_restore(bak));
	va_start(argptr, format);
	while (*format)
	{
		if (*format != '%' && ft_buf_add(ft_get_g_outfd() + result++ * 0,
															format++, 1))
			continue ;
		ret = handle_spec(&format, argptr);
		if (ret == -1 && (result = -1))
			break ;
		result += ret;
	}
	if (FORCE_BUFF_POLICY == IMMIDIATLY_FORCE)
		ft_force_buff();
	global_restore(bak);
	va_end(argptr);
	return (result);
}

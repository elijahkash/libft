/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:50:58 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/02 17:59:05 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include <prf_handle_spec.h>
#include <libft.h>

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
	va_list		argptr;
	int			result;

	errno = 0;
	result = 0;
	ft_set_g_outfd(1);
	ft_set_g_outstr(NULL);
	re_init_argmode();
	if (!is_valid_format(format))
		return (-1);
	va_start(argptr, format);
	while (*format)
	{
		if (*format != '%')
			ft_buf_add(ft_get_g_outfd() + result++ * 0, format++, 1);
		else
			result += handle_spec(&format, argptr);
		if (errno)
		{
			result = -1;
			break ;
		}
	}
	ft_force_buff();
	va_end(argptr);
	return (result);
}

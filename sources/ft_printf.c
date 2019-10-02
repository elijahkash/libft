/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:50:58 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/02 20:07:07 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h> //TODO: need global rename

#include <prf_handle_spec.h>
#include <libft.h>
#include <prf_global_bak.h>

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
	t_global_bak	bak;

	result = 0;
	bak = global_init();
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
	global_restore(bak);
	return (result);
}

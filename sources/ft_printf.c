/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:50:58 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/27 23:07:57 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include <handle_spec.h>
#include <libft.h>

int		g_fd_printf = 1;

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

	result = 0;
	re_init_argmode();
	if (!is_valid_format(format))
		return (-1);
	va_start(argptr, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format++, g_fd_printf);
			result++;
		}
		else
			result += handle_spec(&format, argptr);
		if (errno)
		{
			result = -1;
			break ;
		}
	}
	va_end(argptr);
	return (result);
}

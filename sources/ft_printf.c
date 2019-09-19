/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:50:58 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/19 19:49:11 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <ft_printf_spec.h>

#include <errno.h>
#include <stdarg.h>

static int	is_valid_format(const char *format)
{
	while (*format)
		if (*format != '%')
			format++;
		else if (!is_valid_spec(&format))
			return (0);
	return (1);
}

//TODO: обработка отрицательных значений по * (и без нее)
//TODO: locale.h
int			ft_printf(const char *format, ...)
{
	va_list		argptr;
	int			result;

	result = 0;
	if (!is_valid_format(format))
		return (-1);
	va_start(argptr, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format++);
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

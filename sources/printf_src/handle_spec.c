/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:57:15 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/19 23:05:07 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_spec.h>

#include <libft.h>

const char	*read_spec(const char *format, t_specifications_def *spec)
{
	return (format);
}

int		print_spec(t_specifications_def spec, va_list argptr)
{
	int res;

	res = 0;
	return(res);
}

int		check_spec(t_specifications_def spec)
{
	return (0);
}

int		is_valid_spec(const char *format)
{
	t_specifications_def spec;

	if (*format++ != '%')
		return (0);
	ft_bzero(&spec, sizeof(t_specifications_def));
	if (!read_spec(format, &spec))
		return (0);
	if (check_spec(spec))
		return (0);
	return (0);
}

int		handle_spec(const char **format, va_list argptr)
{
	t_specifications_def	spec;

	if (*(*format)++ != '%')
		return (0);
	ft_bzero(&spec, sizeof(t_specifications_def));
	*format = read_spec(format, &spec);
	return (print_spec(spec, argptr));
}

int		is_valid_format(const char *format)
{
	while (*format)
		if (*format != '%')
			format++;
		else if (!is_valid_spec(&format))
			return (0);
	return (1);
}

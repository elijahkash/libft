/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:57:15 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/20 16:45:15 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_spec.h>

#include <libft.h>

int		print_spec(t_specifications_def spec, va_list argptr)
{
	int res;


	spec.spec = argptr ? 1 : 0;

	res = 0;
	return(res);
}

int		check_spec(t_specifications_def spec)
{
	if (!spec.spec)
		return (-1);
	if (!(spec.flags & specs_def[spec.spec - 1].flags))
		return (-1);
	if (!(spec.sizes & specs_def[spec.spec - 1].sizes))
		return (-1);
	if (spec.width && !specs_def[spec.spec - 1].width)
		return (-1);
	if (spec.precision && !specs_def[spec.spec - 1].precision)
		return (-1);
	if (spec.flags & FLAG_PLUS)
		spec.flags &= (~FLAG_SPACE);
	if (spec.precision)
		spec.flags &= (~FLAG_ZERO);
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
	*format = read_spec(*format, &spec);
	return (print_spec(spec, argptr));
}

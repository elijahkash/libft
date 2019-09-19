/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:57:15 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/19 19:40:13 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_spec.h>

static int	is_valid_spec(const char **format)
{
	if (*(*format)++ != '%')
		return (0);
}

static int	handle_spec(const char **format, va_list argptr)
{
	int result;

	if (*(*format)++ != '%')
		return (0);
	result = 0;

	return (result);
}

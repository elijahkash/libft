/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 21:04:25 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/02 17:12:48 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_extend_dollar.h>

#include <libft.h>

int				is_dollar(const char *format)
{
	if (ft_isdigit(*format) && *format != '0')
	{
		format = ft_skip_digits(format);
		if (*format == '$')
			return (1);
	}
	return (0);
}

const char		*skip_dollar(const char *format)
{
	format = ft_skip_digits(format);
	format++;
	return (format);
}

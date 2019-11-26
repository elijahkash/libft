/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_item_by_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:41:18 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 20:44:48 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_get_item_by_size.h>

#include <prf_printf_spec.h>
#include <libft.h>

long long int			get_dec_item_by_size(va_list argptr, int size)
{
	if (size == SIZE_LL)
		return (va_arg(argptr, long long int));
	if (size == SIZE_HH)
		return ((char)va_arg(argptr, int));
	if (size == SIZE_L)
		return (va_arg(argptr, long int));
	if (size == SIZE_H)
		return ((short int)va_arg(argptr, int));
	return (va_arg(argptr, int));
}

unsigned long long int	get_udec_item_by_size(va_list argptr, int size)
{
	if (size == SIZE_LL)
		return (va_arg(argptr, unsigned long long int));
	if (size == SIZE_HH)
		return ((unsigned char)va_arg(argptr, unsigned int));
	if (size == SIZE_L)
		return (va_arg(argptr, unsigned long int));
	if (size == SIZE_H)
		return ((unsigned short int)va_arg(argptr, unsigned int));
	return (va_arg(argptr, unsigned int));
}

long double				get_float_item_by_size(va_list argptr, int size)
{
	if (size == SIZE_L)
		return (va_arg(argptr, double));
	if (size == SIZE_UP_L)
		return (va_arg(argptr, long double));
	return (va_arg(argptr, double));
}

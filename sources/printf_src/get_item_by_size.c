/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_item_by_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:41:18 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/27 21:06:54 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_item_by_size.h>

#include <ft_printf_spec.h>
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

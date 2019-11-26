/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:54:58 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 20:45:40 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_spectostr_funcs.h>

#include <libft.h>

char	*spectostr_string(t_specifications_def spec, va_list argptr)
{
	char	*output;
	char	*arg;
	int		len;

	arg = va_arg(argptr, char *);
	if (!arg)
		arg = "(null)";
	len = ft_strlen(arg);
	if (spec.precision != NOT_DETERM && len > spec.precision)
		len = spec.precision;
	output = (char *)ft_malloc(1 + len);
	if (!output)
		return (NULL);
	ft_memcpy(output, arg, len);
	output[len] = '\0';
	return (output);
}

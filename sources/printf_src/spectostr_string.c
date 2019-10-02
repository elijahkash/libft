/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:54:58 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/02 17:11:21 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_spectostr_funcs.h>

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
	output = (char *)malloc(1 + len);
	if (!output)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memcpy(output, arg, len);
	output[len] = '\0';
	return (output);
}

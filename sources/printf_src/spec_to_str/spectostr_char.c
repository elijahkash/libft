/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:16:53 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 20:45:47 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_spectostr_funcs.h>

#include <libft.h>

char	*spectostr_char(t_specifications_def spec, va_list argptr)
{
	char	*output;
	char	arg;

	arg = (char)va_arg(argptr, int);
	output = (char *)ft_malloc(2);
	if (!output)
		return (NULL);
	output[0] = arg;
	output[1] = '\0';
	spec.spec = spec.spec;
	return (output);
}

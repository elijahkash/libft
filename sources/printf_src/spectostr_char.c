/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:16:53 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/27 21:07:55 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <spectostr_funcs.h>

char	*spectostr_char(t_specifications_def spec, va_list argptr)
{
	char	*output;
	char	arg;

	arg = (char)va_arg(argptr, int);
	output = (char *)malloc(2);
	if (!output)
	{
		errno = ENOMEM;
		return (NULL);
	}
	output[0] = arg;
	output[1] = '\0';
	spec.spec = spec.spec;
	return (output);
}

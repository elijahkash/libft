/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:47:30 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/04 13:34:23 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_spectostr_funcs.h>

#include <prf_double.h>
#include <stdlib.h>
#include <prf_get_item_by_size.h>
#include <libft.h>

char	*spectostr_float(t_specifications_def spec, va_list argptr)
{
	char			*output;
	long double		test;

	if (!(spec.flags & FLAG_COMMA))
		output = (char *)malloc(spec.precision + 5005 > 25000 ?
							spec.precision + 5005 : 25000);
	else
		output = (char *)malloc(spec.precision + 5005 > 25000 ?
								(int)(spec.precision * 1.5) + 8005 : 35000);
	if (!output)
		return (NULL + (errno = ENOMEM) * 0);
	test = get_float_item_by_size(argptr, spec.sizes);
	output[0] = '\0';
	prf_dblcalc(test, output, spec);
	return (output);
}

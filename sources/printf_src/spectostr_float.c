/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:47:30 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/02 16:55:01 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <spectostr_funcs.h>

#include <double.h>

char	*spectostr_float(t_specifications_def spec, va_list argptr)
{
	char			*output;
	int				len;
	long double		test;

	output = (char *)malloc(spec.precision + 5005 > 25000 ?
							spec.precision + 5005 : 25000);
	if (!output)
		return (NULL + (errno = ENOMEM) * 0);
	test = get_float_item_by_size(argptr, spec.sizes);
	output[0] = '\0';
	prf_dblcalc(test, output, spec);
	return (output);
}

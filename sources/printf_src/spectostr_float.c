/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:47:30 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/26 18:19:03 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <spectostr_funcs.h>


#include <stdio.h>

char	*spectostr_float(t_specifications_def spec, va_list argptr)
{
	char	*output;
	char	tmp[5000];
	int		len;
	long double test;

//	ft_getsnbr_base(get_dec_item_by_size(argptr, spec.sizes), DEC_BASE, tmp);
	test = get_float_item_by_size(argptr, spec.sizes);
	if (spec.flags & FLAG_OCTT)
		sprintf(tmp, "%#.*Lf", spec.precision, test);
	else
		sprintf(tmp, "%.*Lf", spec.precision, test);
	len = ft_strlen(tmp);
	output = (char *)malloc(len + 1);
	if (!output)
		return (NULL + (errno = ENOMEM) * 0);
	ft_memcpy(output, tmp, len + 1);
	return (output);
}
